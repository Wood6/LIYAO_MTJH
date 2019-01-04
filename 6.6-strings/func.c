#include <stdio.h>

int* g_pointer;

void func()
{
	*g_pointer = (int)"liyao test!";

    return;
}
