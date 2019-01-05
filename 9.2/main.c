// 内嵌汇编完成系统调用：实现printf() 和 exit的系统调用
#include <stdio.h>

int main()
{
    char* s = "liyao test!\n";
    int l = 11;
    printf("main begin\n");

    // 利用系统调用实现的printf功能
    asm volatile(
         "movl $4, %%eax\n"   // 功能号为4的系统调用（sys_write）
         "movl $1, %%ebx\n"   // 指定sys_write的输出目标，1为标准输出
         "movl %0, %%ecx\n"   // 指定输出的字符串的地址
         "movl %1, %%edx\n"   // 指定输出字符串的长度
         "int $0x80     \n"   // 执行系统调用
         :   // 省略输出参数
         : "r"(s), "r"(l)     // 把参数s和l放入寄存器
         : "eax", "ebx", "ecx", "edx" // 保留寄存器
         );

	sleep(10);
	
    // 执行sys_exit系统调用
    asm volatile(
        "movl $1,  %eax\n"  // 指定编号为1的系统调用（sys_exit）
        "movl $42, %ebx\n"   // 指定sys_exit的参数，即退出码
        "int $0x80     \n"   // 执行系统调用
        );

    printf("main end\n");

    return 0;
}
