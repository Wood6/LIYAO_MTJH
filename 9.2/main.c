// ��Ƕ������ϵͳ���ã�ʵ��printf() �� exit��ϵͳ����
#include <stdio.h>
#include <string.h>

int main()
{
    char* s = "liyao test!\n";
    int len = strlen(s);
	
    printf("main begin\n");

    // ����ϵͳ����ʵ�ֵ�printf����
    asm volatile(
         "movl $4, %%eax\n"   // ���ܺ�Ϊ4��ϵͳ���ã�sys_write��
         "movl $1, %%ebx\n"   // ָ��sys_write�����Ŀ�꣬1Ϊ��׼���
         "movl %0, %%ecx\n"   // ָ��������ַ����ĵ�ַ
         "movl %1, %%edx\n"   // ָ������ַ����ĳ���
         "int $0x80     \n"   // ִ��ϵͳ����
         :   // ʡ���������
         : "r"(s), "r"(len)     // �Ѳ���s��l����Ĵ���
         : "eax", "ebx", "ecx", "edx" // �����Ĵ���
         );
	
    // ִ��sys_exitϵͳ����
    asm volatile(
        "movl $1,  %eax\n"  // ָ�����Ϊ1��ϵͳ���ã�sys_exit��
        "movl $42, %ebx\n"   // ָ��sys_exit�Ĳ��������˳���
        "int $0x80     \n"   // ִ��ϵͳ����
        );

    printf("main end\n");

    return 0;
}
