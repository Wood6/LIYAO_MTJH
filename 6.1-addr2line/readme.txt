1、执行命令：
	ulimit -c umlimited
	gcc -g main.c -o main.out
	dmesg core
	addr2line -f -e main.out 080483fa > result.txt

2、特殊命令说明：
	ulimit -c umlimited  shell启动进程所占用的资源，-c 为设置core文件的最大值，umlimited表示不限制
	ulimit -c 0   限制大小为0，即关闭生成core文件
	core文件详解，见文件：
	
	
