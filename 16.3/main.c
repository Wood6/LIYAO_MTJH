// 解决16.2的问题
#include <stdio.h>
#include "global.h"

int main()
{
    define_print();
    
    printf("main() : %s\n", g_name);
    
    return 0;
}
