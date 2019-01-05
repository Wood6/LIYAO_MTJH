// 用链接脚本指定应用程序的入口函数
#include <stdio.h>
#include <stdlib.h>

int s1;
int s2 = 2;
extern int S1;
extern int S2;

int mymain(int argc, char* argv[])
{
	printf("&s1 = %p\n", &s1);
	printf("&s1 = %p\n", &s2);
	printf("&S1 = %p\n", &S1);
	printf("&S2 = %p\n", &S2);
	
	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);
	printf("S1 = %d\n", S1);
	printf("S2 = %d\n", S2);
	
	S1 = 100;
	S2 = 200;
	
	printf("S1 = %d\n", S1);
	printf("S2 = %d\n", S2);

	printf("liyao test!\n");
	
	exit(0);
}