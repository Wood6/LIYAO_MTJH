// 解决16.2的问题
#include <stdio.h>
#include "global.h"

char g_name[] = "liyao test!";

void define_print()
{
    printf("define_print() : %s\n", g_name);
}
