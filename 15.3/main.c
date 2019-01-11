// 返回值是结构体的测试
#include <stdio.h>

struct ST
{
	int x;
	int y;
	int z;
};

struct ST f(int x, int y, int z)
{
	struct ST st = {0};
	
	printf("f() : &st = %p\n", &st);
	
	st.x = x;
	st.y = y;
	st.z = z;
	
	return st;
}

// 函数返回值用于赋值操作
void assign()
{
	struct ST st = {0};
	
	printf("assign() : &st = %p\n", &st);
	
	st = f(1, 2, 3);
	
	printf("assign() : &st = %p\n", &st);
	printf("assign() : st.x = %d\n", st.x);
	printf("assign() : st.y = %d\n", st.y);
	printf("assign() : st.z = %d\n", st.z);
}

// 函数返回值用于初始化
void init()
{
	struct ST st = f(4, 5, 6);
	
	printf("init() : &st = %p\n", &st);
	printf("init() : st.x = %d\n", st.x);
	printf("init() : st.y = %d\n", st.y);
	printf("init() : st.z = %d\n", st.z);
}

int main()
{
	printf("---------------------\n");
	init();
	printf("---------------------\n");
	assign();
	printf("---------------------\n");
	
	return 0;
}