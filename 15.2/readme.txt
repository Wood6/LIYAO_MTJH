1、结合汇编可以看到，默认的调用约定 __cdecl__ 下，返回值是保存在eax寄存器里面的
	mov    %eax,-0xc(%ebp)  
	ebp-0xc恰好是r的地址
	再汇编看test函数，也是将返回值保存在eax里面

2、三个函数的函数体一样，但三个函数的汇编码不一样，这正是函数调用约定不一样导致的!

3、补充一点：ABI中的函数调用约定，也规定了函数被编译后对应最终符号名（这个在编译制作动态连接库时影响特别明显），可以另外做个实验编译，在linux下面这个影响看不出来，有兴趣可以在windows下面编译个库看看！