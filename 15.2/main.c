// 函数调用时，参数如何入栈？
// 函数返回时，返回值在哪里？
// ABI 调用约定：规范函数参数和返回值的细节（参数入栈顺序、谁进行栈清理，返回值怎样返回的等约定）
#include <stdio.h>

int test(int a, int b, int c)
{
	return a + b + c;
}

// 三个不同的调用约定，反汇编观察参数入栈、清栈者等信息
void __attribute__((__cdecl__)) func_1(int a, int b)
{
}

void __attribute__((__stdcall__)) func_2(int a, int b)
{
}

void __attribute__((__fastcall__)) func_3(int a, int b)
{
}

int main()
{
	int a = 1;
	int b = 2;
	int r = test(1, 2, 3);   // 反汇编，观察函数的返回值（存放于 eax 中）
	
	func_1(a, b);
	func_2(a, b);
	func_3(a, b);
	
	printf("r = %d\n", r);
	
	return 0;
}