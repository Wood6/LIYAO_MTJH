因为连接脚本没有按linux平台规范来设置段的链接地址，所以导致运行时段错误
linux平台规范是：进程代码段(.text）的合法起始地址为[0x8048000, 0x8049000]

