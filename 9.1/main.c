// c语言内嵌汇编体验
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0;
    int input = 1;

    int a = 2;
    int b = 3;
	
	printf("result = %d\n", result);
	printf("input = %d\n", input);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("==================================\n");
	
	// 将 input 的值赋值给 result
    asm volatile (
        "movl %1, %0\n"   // movl中的l表示long，%0表示寄存器列表（含输出和输入）中的第1个寄存器
                          // %1表示寄存器列表中的第2个寄存器，以此类推
        : "=r"(result)    // 输出变量与esi或edi寄存器关联（其中esi或edi由编译器自动分配）
        : "r"(input)      // 输入变量与esi或edi寄存器关联
    );

    printf("result = %d\n", result); // 1
    printf("input = %d\n", input);   // 1

    // 交换a和b的值
    asm volatile(
        "movl %%eax, %%ecx\n"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx\n"
        : "=a"(a), "=b"(b)   // 将eax输出到a，ebx输出到b
        : "a"(a), "b"(b)     // a放入eax，b放入ebx
        );

    printf("a = %d\n", a);   // a = 3
    printf("b = %d\n", b);   // b = 2

    return 0;
}

