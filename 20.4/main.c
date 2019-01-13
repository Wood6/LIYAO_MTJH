// 定时器程序，防御性编程示例
#include <stdio.h>
#include "timer.h"

void callback_1(Timer* t, void* data)
{
    printf("I'm callback for t1.\n");
}

int main()
{
    Timer* t1 = NULL;
    
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