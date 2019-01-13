/**************************************************
 *                                                *
 *                  D.T.Software                  *
 *                                                *
 **************************************************/
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "timer.h"

#define MAX 32
#define GAP 10

struct STimer
{
    int id;                    // 定时器id
    int interval;              // 间隔时间，
    int current;               // 当前定时了多长时间，与上面相等时，触发回调函数
    TimerCallback* callback;   // 回调函数
    void* data;                // 回调函数的参数
};

static struct STimer* g_timers[MAX];     // 最多可以有 MAX 计时器
static volatile int g_run;               // volatile 这里就是多线程标记变量的用法
static pthread_mutex_t mutex;            // 锁，多线程中常用

// 单独的线程执行，相当于时针源，采用的软件定时
static void* Runtime(void* args)
{
    int i = 0;
    
    while( g_run )
    {     
        pthread_mutex_lock(&mutex); 
        
		// 遍历每个定时器模块
        for(i=0; (i<MAX) && g_run; i++)
        {
			// 将遍历到的定时器模块取出来，用来更新当前时间，时间到执行回调函数
            struct STimer* st = g_timers[i];
            
            if( (st != NULL) && (st->callback != NULL) )
            {
                st->current += GAP;             // 当前时间加上时间流逝量，10毫秒
            
				// 当前时间到达了定时器间隔时间
                if( st->current >= st->interval ) 
                {
					// 执行回调函数
                    st->callback(st, st->data);
					// 再又将当前时间的清0
                    st->current = 0;
                }
            }
        }
        
        pthread_mutex_unlock(&mutex);  
        
        usleep(GAP * 1000);         // 这里采用的是软件定时，休眠10毫秒
    }
    
	// 没有定时器执行了，释放所有定时器
    for(i=0; i<MAX; i++)
    {
        free(g_timers[i]);
    }
}


void TimerInitialize()
{
	pthread_t tid = 0;
	
	g_run = 1;

	pthread_create(&tid, NULL, Runtime, NULL);
}

void TimerFinalize()
{
    g_run = 0;
}

Timer* CreateTimer(int interval, TimerCallback* callback, void* data)
{
    int id = 0;
	// 申请堆空间用来做定时器模块
    struct STimer* ret = (struct STimer*)malloc(sizeof(struct STimer));
    
    if( ret != NULL )
    { 
        pthread_mutex_lock(&mutex);   
        
		// 遍历定时器模块数组
        for(id=0; id<MAX; id++)
        {
			// 哪个位置是空的
            if( g_timers[id] == NULL )
            {
				// 将这个定时器加到这个数组中
                g_timers[id] = ret;
                break;
            }
        }
        
        pthread_mutex_unlock(&mutex);
        
		// 更新到数组中
        if( id < MAX )
        {	
			// 定时器id、间隔时间、当前时间置0、绑定回调函数、参数
            ret->id = id;
            ret->interval = interval;
            ret->current = 0;
            ret->callback = callback;
            ret->data = data;
        }
        else    // 定时器以达到最大，释放申请的堆空间
        {
            free(ret);
            ret = NULL;
        }
    }
    
    return ret;
}

void DestroyTimer(Timer* timer)
{
    if( timer != NULL )
    {
        struct STimer* st = (struct STimer*)timer;
        
		pthread_mutex_lock(&mutex);   
	
		g_timers[st->id] = NULL;
		
		pthread_mutex_unlock(&mutex);   
		
		free(st);
    }
}

