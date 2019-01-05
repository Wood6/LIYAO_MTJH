// 用链接脚本指定应用程序的入口函数
#include <stdio.h>
#include <stdlib.h>

int s1;
int s2 = 2;

int main(int argc, char* argv[])
{
	printf("&s1 = %p\n", &s1);
	printf("&s1 = %p\n", &s2);
	
	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);

	printf("liyao test!\n");
	
	exit(0);
}
