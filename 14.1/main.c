// 验证不同平台的ABI对结构体对齐方式的设定（linux压缩存储、windows非压缩存储）
#include <stdio.h>

// 未初始化的全局变量进入.bss段，程序加载时 .bss段会全为0
struct {
	short s : 9;
	int j : 9;
	char c;
	short t : 9;
	short u : 9;
	char d;
} s;

int main(int argc, char* argv[])
{
	int i = 0;
	int* p = (int*)&s;
	
	printf("sizeof = %d\n", sizeof(s));
	
	s.s = 0x1FF;
	s.j = 0x1FF;
	s.c = 0xFF;
	s.t = 0x1FF;
	s.u = 0x1FF;
	s.d = 0xFF;
	
	for(i=0; i<sizeof(s)/sizeof(*p); i++)
	{
		printf("%X\n",*p++);
	}
	
	return 0;
}
/*
输出结果：
gcc + ubuntu 下（内存布局如左图：压缩方式）
sizeof = 12
FF03FFFF
1FF01FF
FF

gcc + Window 下：（内存布局如右图：非压缩方式）
sizeof(s) = 16
1FF
FF01FF
1FF01FF
FF

vc + window 下：（内存布局如右图：非压缩方式）
sizeof(s) = 16
1FF
1FF00FF
FF01FF
*/