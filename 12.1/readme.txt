// watch.c
// gcc -g watch.c -o watch.out -lpthread
[root@localhost 12]# gdb watch.out
(gdb) start(gdb) watch g_var //打数据断点
(gdb) info breakpoints //查看数据断点
(gdb) continue //程序执行到数据断点处
Continuing.
[New Thread 0xb7ff5b70 (LWP 4906)]
g_var = 0
g_var = 0
g_var = 0
g_var = 0
g_var = 0
[Switching to Thread 0xb7ff5b70 (LWP 4906)]
Hardware watchpoint 2: g_var //断点被触发
Old value = 0 //g_var 原有的值
New value = 1 //g_var 新的值
thread_func (args=0x0) at watch.c:13 //g_var 在 watch.c 的第 13 行处发生更改，第12行执行完才改变，所以才第13行会监测到这个改变！
(gdb) print g_var //打印 g_var 的值
(gdb) print /a &g_var //打印 g_var 的地址
$2 = 0x8049818 <g_var>
(gdb) x /4bx &g_var //查看从&g_var 地址开始处的 4 字节内容
0x8049818 <g_var>: 0x01 0x00 0x00 0x00
(gdb) x /1bx 0x804981 //查看从&g_var 地址开始处的 1 字节内容
0x8049818 <g_var>: 0x01
(gdb) continue
(gdb) quit



// frame.c
[root@localhost 12]# gdb frame.out
(gdb) start
(gdb) break sum if n==0 //在 sum 函数处打条件断点（当 n==0 时）
(gdb) info breakpoints //查看断点信息
(gdb) continue //执行到断点处(gdb) backtrace //查看函数调用栈
#0 sum (n=0) at frame.c:7
#1 0x080483e5 in sum (n=1) at frame.c:10
#2 0x080483e5 in sum (n=2) at frame.c:10
#3 0x080483e5 in sum (n=3) at frame.c:10
#4 0x080483e5 in sum (n=4) at frame.c:10
#5 0x080483e5 in sum (n=5) at frame.c:10
#6 0x080483e5 in sum (n=6) at frame.c:10
#7 0x080483e5 in sum (n=7) at frame.c:10
#8 0x080483e5 in sum (n=8) at frame.c:10
#9 0x080483e5 in sum (n=9) at frame.c:10
#10 0x080483e5 in sum (n=10) at frame.c:10
#11 0x0804840d in main () at frame.c:20
(gdb) next
(gdb) info args //查看当前 sum 函数的参数值（n==0）
(gdb) frame 7 //切换到编号为 7 的栈桢处
(gdb) info args //查看当前 sum 函数的参数值（n==7）
(gdb) info locals //查看局部变量的值
(gdb) frame 0 //切换到第 0 栈桢处
(gdb) info registers //查看寄存器的值
(gdb) info frame //查看栈桢信息
Stack level 0, frame at 0xbffff440:
eip = 0x80483d1 in sum (frame.c:9); saved eip 0x80483e5
called by frame at 0xbffff470
source language c.
Arglist at 0xbffff438, args: n=0
Locals at 0xbffff438, Previous frame's sp is 0xbffff440
Saved registers:
ebp at 0xbffff438, eip at 0xbffff43c
(gdb) x /1wx 0xbffff438
0xbffff438: 0xbffff468
(gdb) quit

// tricks.c
(gdb) shell gcc -g tricks.c -o tricks.out //利用 shell 进行编译(gdb) shell cat tricks.c //利用 shell 查看 tricks.c 的内容
(gdb) file tricks.out //加载 tricks.out
(gdb) start
(gdb) list tricks.c:18 //显示 tricks.c 第 18 行的内容
(gdb) set listsize 20 //设置 list 显示的行数为 20 行。
(gdb) show listsize //查看 list 显示的行数。
(gdb) break tricks.c:18
(gdb) continue
(gdb) display /d i //设置自动打印 i 的值，断点时会自动打印
(gdb) display /d i*i //设置自动打印 i*i 的值，断点时会自动打印
(gdb) display /a &i //设置自动打印 i*i 的地址
(gdb) continue
(gdb) undisplay //取消自动打印
(gdb) whatis g_var //查看 g_var 的类型: type = int
(gdb) ptype g_var //查看 g_var 的类型，与 whatis 结果一样
(gdb) whatis func //查看 func 的类型, type = int()
(gdb) ptype func //查看 func 的类型，与 whatis 结果一样
(gdb) whatis struct ST //查看 struct ST 的类型:type = struct ST
(gdb) ptype struct ST //查看 struct ST 的定义，也可查看由 struct ST定义的变量类型
type = struct ST {
int i;
int j;
}
(gdb) info variables //查看程序中所有的符号，如 g_var
(gdb) info functions //查看所有函数，如 func、 main
(gdb) quit