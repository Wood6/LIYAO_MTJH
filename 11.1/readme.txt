//更详细过程见笔记：
//软件断点及调试
[root@localhost 11]# gdb test.out //调试 test.out
(gdb) set args 12345 //设置命令行参数为 12345
(gdb) start //开始执行 test.out，会暂停在 main 函数
(gdb) break test.c:37 //在 test.c 的第 37 行处打个断点
(gdb) info breakpoints //查看断点信息
(gdb) continue //恢复执行，会一直运行到第 37 行
(gdb) next
(gdb) print i //打印 i 的值
$1 = 1
(gdb) set var i=100 //设置 i 的值为 100
(gdb) print i
$2 = 100
(gdb) tbreak test.c:42 //在 42 行下断点
(gdb) continue //运行至 42 行，即 func()函数。该函数会出现异
常
(gdb) jump 46 //跳过 func 函数，跳到46行执行
main() : end... //程序正常结束！
Program exited normally.
(gdb) quit


//在函数名下断点
[root@localhost 11]# gdb test.out
(gdb) start
(gdb) break func //在 func 函数打断点
(gdb) info breakpoints
(gdb) continue //执行至 func 函数入口处
(gdb) return //从 func 函数中返回


//测试硬件断点
[root@localhost 11]# gdb test.out
(gdb) start
(gdb) show can-use-hw-watchpoints //查看是否支持的硬件断点
(gdb) hbreak func //在 func 函数下硬件断点
(gdb) info breakpoints //查看断点信息(gdb) continue //运行到 func 函数的入口处
(gdb) print g_pointer //查看 g_pointer 的值（为 NULL）
(gdb) set var g_pointer=(int*)malloc(sizeof(int)) //设置 g_pointer
(gdb) print g_pointer //查看 g_pointer 的值（本例为 04a008）
(gdb) continue //继续运行，会正常结束！
(gdb) quit