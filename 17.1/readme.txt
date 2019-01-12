不带优化选项编译：gcc -g device.c main.c -o main-NoOptimize.out -lpthread
带优化选项编译：gcc -O3 -g device.c main.c -o main-Optimize.out -lpthread

./main-NoOptimize.out  执行是期望结果
./main-Optimize.out 执行不是期望结果

root@ubuntu:/Wood_Work/LIYAO_MTJH/17.1# ./main-NoOptimize.out 
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
init_device() - device status : g_ready = 1
main() - launching device : g_ready = 1
main() - device status : g_ready = 1
root@ubuntu:/Wood_Work/LIYAO_MTJH/17.1# ./main-Optimize.out 
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
init_device() - device status : g_ready = 1
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
^C                                                  // Ctrl+c中断的
root@ubuntu:/Wood_Work/LIYAO_MTJH/17.1# 


产品代码最终发布时一般都是会加上优化选项的，代码完全没动，就编译成可执行程序时加上了优化选项，结果就不是预期了！！！！
怎么回事？？？

问题分析：
	1、编译优化时，编译器根据当前文件进行优化
	2、编译器能够发现变量“不可能”被改变（const全局变量）
	3、为了效率上的提高，编译器将变量值进行缓存
	4、缓存的方式为：把变量从内存中读取进入寄存器
	5、每次访问变量时直接从寄存器读取对应值
	
解决方案：使用volatile修饰可能被“意外”修改的变量（内存）
	1、volatile 修饰的变量是一种“易变的”变量
	2、volatile 可理解为“编译器警告指示字”
	3、volatile 告诉编译器必须每次去内存中取变量值
	
拓展问题：如何理解 const 和 volatile 同时修饰变量？const 表示这个变量时“不可改变的”，volatile 表示这个变量是“易变的”，那么这两者在语义上是否矛盾？

const 和 volatile
	1、const 表示被修饰的变量不能出现在赋值符合左边
	2、volatile 表示使用变量时直接从内存去取值
	3、const 和 volatile 同时修饰变量时互不影响其含义
	综上：两者可以同时修饰变量，两者不冲突！！！
	
小结：
	1、编译器优化时，编译器只根据当前文件进行优化
	2、编译器的优化策略可能造成一些意外
	3、volatile 强制编译器必须每次从内存中取变量值
	4、const 和 volatile 同时修饰变量时互不影响其含义

		  
	
