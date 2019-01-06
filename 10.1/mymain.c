// 模拟嵌入式开发：做的体积最小
void print(const char* s, int l);
void myexit(int code);

void mymain()
{
    print("liyao test!\n", 12);
    
    myexit(0);
}

void print(const char* s, int l)
{
	// 内嵌汇编直接系统调用
    asm volatile(
        "movl $4, %%eax\n" // 编号为4的系统调用(sys_write)
        "movl $1, %%ebx\n" // 标准输出
        "movl %0, %%ecx\n" // 输入字符串的地址
        "movl %1, %%edx\n" // 字符串的长度
        "int $0x80     \n" // 执行系统调用
        : // 没有输出参数
        : "r"(s), "r"(l)
        : "eax", "ebx", "ecx", "edx"    // 保留寄存器      
    );
}

void myexit(int code)
{
	// 内嵌汇编直接系统调用
    asm volatile(
        "movl $1, %%eax\n"  // 功能号为1的系统调用（sys_exit)
        "movl %0, %%ebx\n"  // 退出码
        "int $0x80     \n"  // 执行系统调用
        :
        : "r"(code)
        : "eax", "ebx"
    );
}