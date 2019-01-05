// c������Ƕ�������
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0;
    int input = 1;

    int a = 2;
    int b = 3;
	
	printf("result = %d\n", result);
	printf("input = %d\n", input);
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("==================================\n");
	
	// �� input ��ֵ��ֵ�� result
    asm volatile (
        "movl %1, %0\n"   // movl�е�l��ʾlong��%0��ʾ�Ĵ����б�����������룩�еĵ�1���Ĵ���
                          // %1��ʾ�Ĵ����б��еĵ�2���Ĵ������Դ�����
        : "=r"(result)    // ���������esi��edi�Ĵ�������������esi��edi�ɱ������Զ����䣩
        : "r"(input)      // ���������esi��edi�Ĵ�������
    );

    printf("result = %d\n", result); // 1
    printf("input = %d\n", input);   // 1

    // ����a��b��ֵ
    asm volatile(
        "movl %%eax, %%ecx\n"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx\n"
        : "=a"(a), "=b"(b)   // ��eax�����a��ebx�����b
        : "a"(a), "b"(b)     // a����eax��b����ebx
        );

    printf("a = %d\n", a);   // a = 3
    printf("b = %d\n", b);   // b = 2

    return 0;
}

