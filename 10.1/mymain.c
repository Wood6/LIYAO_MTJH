// ģ��Ƕ��ʽ���������������С
void print(const char* s, int l);
void myexit(int code);

void mymain()
{
    print("liyao test!\n", 12);
    
    myexit(0);
}

void print(const char* s, int l)
{
	// ��Ƕ���ֱ��ϵͳ����
    asm volatile(
        "movl $4, %%eax\n" // ���Ϊ4��ϵͳ����(sys_write)
        "movl $1, %%ebx\n" // ��׼���
        "movl %0, %%ecx\n" // �����ַ����ĵ�ַ
        "movl %1, %%edx\n" // �ַ����ĳ���
        "int $0x80     \n" // ִ��ϵͳ����
        : // û���������
        : "r"(s), "r"(l)
        : "eax", "ebx", "ecx", "edx"    // �����Ĵ���      
    );
}

void myexit(int code)
{
	// ��Ƕ���ֱ��ϵͳ����
    asm volatile(
        "movl $1, %%eax\n"  // ���ܺ�Ϊ1��ϵͳ���ã�sys_exit)
        "movl %0, %%ebx\n"  // �˳���
        "int $0x80     \n"  // ִ��ϵͳ����
        :
        : "r"(code)
        : "eax", "ebx"
    );
}