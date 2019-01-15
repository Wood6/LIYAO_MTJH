#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "errtmr.h"

void demo1()
{
    error_t err = ERROR_T(ERROR_TIMER_ALLOC_NOTIMER);             // 错误码
    
    printf("Module Timer: %X\n", MODULE_TIMER);                   // 直接打印出模块id
    printf("Error Sample: %X\n", err);                            // 错误码
    printf("Error Mark: %X\n", (err & ERROR_MARK) != 0);          // 是不是错误码，是：1，不是：0
    printf("Module ID: %X\n", MODULE_ID(err));                    // 模块id，看与上面 MODULE_TIMER 是不是一样
    printf("Module Error ID: %X\n", MODULE_ERROR(err));           // 模块错误号  
}

// 异常处理，
// 若是异常但没有处理成功也会执行 exit(e) 退出进程，返回错误码
// 异常处理成功，不会执行exit(e)
// 注意，错误码过大时，exit()返回的可能不是程序中的错误码。而是系统的错误码
#define HANDLER(err) do {    \
    int e=err;               \
    if((e & ERROR_MARK) &&   \
        !err_handler(e))     \
        exit(e);             \
} while(0)

// 函数名 [文件名:行数] 错误码
#define LOG(f, e)  printf("%s [%s:%d] => %X\n", #f, __FILE__, __LINE__, e)

int do_task()
{
    // ... ... 
    
    return ERROR_T(ERROR_TIMER_STATE_INVSTATE);   //ERROR_T(ERROR_TIMER_STATE_INVSTATE) 或者 return 0;
}

int sub_func()
{
    int ret = 0;
    
    ret = do_task();
    
	// 是错误码的情况
    if(ret & ERROR_MARK)
        LOG(sub_func, ret);
    
    // return 0 for no exception
    return ret; 
}

// 异常处理，异常处理好了返回1，没有异常返回0
int err_handler(int e)
{
    int ret = 0;

	// e最高为为1，是异常的情况
    if( e & ERROR_MARK )
        switch(e ^ ERROR_MARK)
        {
            // handle something unexcepted 
            case ERROR_TIMER_STATE_INVSTATE:
                printf("Reset Timer State!!!\n");
                ret = 1;
                break;
        }
    else
        ret = 1;
    
    // return 1 for success handling
    return ret; 
}

void demo2()
{
    printf("demo2() begin ...\n");
    
    HANDLER(sub_func());
    
    printf("demo2() end ...\n");
}

int main()
{
    demo1();
    
    printf("\n");
    
    demo2();
    
    return 0;
}