#include <stdio.h>

// ȫ��ָ�룬����Ϊû�г�ʼ�����ᱻ����.bss�Σ����൱���Ǹ�ֻ��0��ַ��ָ��
int* g_pointer;

void func(void)
{
	// ��0��ַдֵ���϶��ᱨ�δ���
	*g_pointer = (int)"liyao test!";
}

int main(int argc, char* argv[])
{
	func();

	return 0;
}