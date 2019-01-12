// 使用 volatile 解决17.1的问题
#include <stdio.h>
#include <pthread.h>

// cosnt 表示变量 g_ready 不能出现在赋值符合左边，var是一个只读变量
// volatile 使用变量var时直接从内存取值，不进行任何方式的优化
extern const volatile int g_ready;

int main()
{
    launch_device();

    while(g_ready == 0)
    {
        sleep(1);
        
        printf("main() - launching device : g_ready = %d\n", g_ready);
    }
    
    printf("main() - device status : g_ready = %d\n", g_ready);

    return 0;
}
