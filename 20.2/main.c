// 没有防御性编程不好影响示例1
#include <stdio.h>
#include "timer.h"

void callback_1(Timer* t, void* data)
{
    printf("I'm callback for t1.\n");
}

int main()
{
    Timer* t1 = NULL;
    
	/* 多次掉用初始化，相当于创建了多个线程同时更新时针源，导致程序定时不是我们预期的，会比我们预期快很多 */
    TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
	TimerInitialize();            // 模块初始化
    
    t1 = CreateTimer(1000, callback_1, NULL);   // 创建一个定时器
    
    getchar();
    
    DestroyTimer(t1);             // 模块销毁
     
    TimerFinalize();              // 模块终止
    
    return 0;
}