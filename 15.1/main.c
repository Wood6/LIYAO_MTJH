// linux 栈帧结构
#include <stdio.h>

#define PRINT_STACK_FRAME_INFO() do                            \
{									                           \
	char* ebp = NULL;				                           \
	char* esp = NULL;				                           \
					                           				   \
	asm volatile (				                               \
		"movl %%ebp, %0\n"				                       \
		"movl %%esp, %1\n"				                       \
		:"=r"(ebp), "=r"(esp)                                  \
	);                                                         \
	                                                           \
	printf("ebp = %p\n", ebp);                                 \
	printf("previous ebp = 0x%x\n", *((int*)ebp));             \
	printf("return address = 0x%x\n", *((int*)(ebp + 4)));     \
	printf("previous esp = %p\n", ebp + 8);                    \
	printf("esp = %p\n", esp);                                 \
	printf("&ebp = %p\n", &ebp);                               \
	printf("&esp = %p\n", &esp);                               \
}while(0)

void test(int a, int b)
{
	int c = 3;
	
	printf("=====>> test() : \n");
	
	PRINT_STACK_FRAME_INFO();
	
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
}

void func()
{
	int a = 1;
	int b = 2;
	
	printf("=====>> func() : \n");
	
	PRINT_STACK_FRAME_INFO();
	
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	
	test(a, b);
}

int main(int argc, char* argv[])
{
	printf("=====>> main() : \n");
	
	PRINT_STACK_FRAME_INFO();
	
	func();

	return 0;
}

/* gcc + Ubuntu 输出结果：
=====>> main() : 
ebp = 0xbf825218               
previous ebp = 0x0
return address = 0xb7567af3
previous esp = 0xbf825220
esp = 0xbf8251f0
&ebp = 0xbf825208
&esp = 0xbf82520c
=====>> func() : 
ebp = 0xbf8251e8
previous ebp = 0xbf825218
return address = 0x8048715
previous esp = 0xbf8251f0
esp = 0xbf8251c0
&ebp = 0xbf8251d8
&esp = 0xbf8251dc
&a = 0xbf8251d0
&b = 0xbf8251d4
=====>> test() : 
ebp = 0xbf8251b8                    // 处理器上ebp寄存器中的值，也就是当前栈帧上ebp指针的地址
previous ebp = 0xbf8251e8           // 上一个栈帧ebp指针的地址
return address = 0x8048647          // 返回地址
previous esp = 0xbf8251c0           // 上一个栈帧esp指针的地址
esp = 0xbf825190                    // 处理器上esp寄存器中的值，也就是当前栈帧上esp指针的地址
&ebp = 0xbf8251a8                   // 局部变量ebp的地址，在当前函数的栈帧中 
&esp = 0xbf8251ac                   // 局部变量esp的地址，在当前函数的栈帧中
&a = 0xbf8251c0						// 函数参数a的地址，在上一个函数的栈帧中
&b = 0xbf8251c4                     // 函数参数b的地址，在上一个函数的栈帧中
&c = 0xbf8251a4                     // 局部变量c的地址，在当前函数的栈帧中
								    // 备注：上两个函数的结果分析一样
*/
// 理解易错点1：ebp = 0xbf8251b8
// ebp是处理器上的一个寄存器，是硬件概念，是与内存区不同硬件
// 0xbf8251b8是当前这个硬件寄存器中储存的值，这个值是个内存地址
// 就是当前函数栈帧上的ebp指针的地址0xbf8251b8
// *0xbf8251b8是上一个栈帧的ebp指针的地址
// esp = 0xbf825190同理分析

// 理解易错点2：&ebp = 0xbf8251a8
// 是局部变量ebp的地址，与ebp寄存器无关
// 绝不要一眼看成是ebp寄存器的地址，x86处理器，ebp是与内存不同的概念，没有地址一说
// &esp = 0xbf8251ac 同理分析



