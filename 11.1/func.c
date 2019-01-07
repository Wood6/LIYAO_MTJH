#include <stdio.h>

int* g_pointer;

void func()
{
	*g_pointer = (int)"liyao test!";    // error, 往 0 地址处写内容(.bss段统一初始为0)
	
	return;
}