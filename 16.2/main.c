// 数组与指针混淆使用犯错的示例
#include <stdio.h>

extern char* g_name;

int main()
{
    define_print();
    
    printf("main() : %s\n", g_name);
    
    return 0;
}
