链接脚本中 ENTRY(mymain) 指定应用程序的入口函数为 mymain()
可以通过 objdump -h 和 objdump -S 来验证

编译命令： gcc -g -nostartfiles test.lds main.c -o main.out
注意：依旧需要 nostartfiles 参数，链接时将不使用gcc提供的标准系统启动文件，否则链接会出错，因为_start函数找不到main函数了

mymain() 用return 0返回报了段错误，用exit(0)没有，这个地方放到后面查下是什么原因！！！

