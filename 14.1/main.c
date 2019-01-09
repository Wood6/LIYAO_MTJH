// ��֤��ͬƽ̨��ABI�Խṹ����뷽ʽ���趨��linuxѹ���洢��windows��ѹ���洢��
#include <stdio.h>

// δ��ʼ����ȫ�ֱ�������.bss�Σ��������ʱ .bss�λ�ȫΪ0
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
��������
gcc + ubuntu �£��ڴ沼������ͼ��ѹ����ʽ��
sizeof = 12
FF03FFFF
1FF01FF
FF

gcc + Window �£����ڴ沼������ͼ����ѹ����ʽ��
sizeof(s) = 16
1FF
FF01FF
1FF01FF
FF

vc + window �£����ڴ沼������ͼ����ѹ����ʽ��
sizeof(s) = 16
1FF
1FF00FF
FF01FF
*/