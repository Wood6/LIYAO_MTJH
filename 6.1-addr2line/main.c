#include <stdio.h>

// 全局指针，但因为没有初始化，会被放入.bss段，就相当于是个只想0地址的指针
int* g_pointer;

void func(void)
{
	// 往0地址写值，肯定会报段错误！
	*g_pointer = (int)"liyao test!";
}

int main(int argc, char* argv[])
{
	func();

	return 0;
}