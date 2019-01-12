#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int g_ready = 0;

// 休眠5秒后才改变 g_ready 的值，以此模拟硬件的操作
void* init_device(void* args)
{
    sleep(5);

    g_ready = 1;

    printf("init_device() - device status : g_ready = %d\n", g_ready);
}

void launch_device()
{
    pthread_t tid = 0;

    pthread_create(&tid, NULL, init_device, NULL);
}
