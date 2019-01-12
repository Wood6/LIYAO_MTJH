#include <stdio.h>
#include <pthread.h>

// cosnt 表示变量g_ready 不能出现在赋值符合左边，var是一个只读变量
extern const int g_ready;

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
