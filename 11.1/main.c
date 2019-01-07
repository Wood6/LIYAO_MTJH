#include <stdio.h>
#include <unistd.h>

extern int* g_pointer;
extern void func();

void test1()
{
	printf("test1() : %p\n", test1);
}

void test2()
{
	printf("test2() : %p\n", test2);
}

void test3()
{
	printf("test3() : %p\n", test3);
}

int main(int argc, char* argv[])
{
	typedef void (TFunc)(); //函数别名
	TFunc* fa[]={test1, test2, test3};
	
	int i = 0;
	
	printf("main(): begin...\n");
	
	for(i=0; i<argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	
	for(i=0; i<100; i++)
	{
		fa[i%3](); //循环调用 test1、 test2、 test3 函数
		sleep(argc>1); //延时，为调试的需要。根据命令行参数个数决定是否休眠 1 秒
	}

	printf("g_pointer = %p\n", g_pointer);
	
	func(); //函数内部可能导致异常

	printf("main() : end...\n");

	return 0;
}