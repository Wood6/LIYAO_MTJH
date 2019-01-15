模块的组织，初始化与销毁的源码分析
先注册模块，注册时挂接回调函数！
将模块按模块按层次放在一个双向链表的数组中，初始化和启动按数组顺序遍历遍历数组中的链表，终止和销毁与初始化顺序相反！

执行上一课 ./main.out 
root@ubuntu:/Wood_Work/LIYAO_MTJH/21.1# ./main.out 

System is going to be up
  Info: timer module is initializing
  Info: memory module is initializing
  Info: timer module is up
  Info: memory module is up

System is going to be down
  Info: memory module is down
  Info: timer module is down
  Info: memory module is destroying
  Info: timer module is destroying
root@ubuntu:/Wood_Work/LIYAO_MTJH/21.1# 


===========================================================
module.c 中，代码可以进一步优化!
优化后， 执行 ./main.out 
root@ubuntu:/Wood_Work/LIYAO_MTJH/21.1# ./main.out 

System is going to be up
  Info: timer module is initializing
  Info: memory module is initializing
  Info: timer module is up
  Info: memory module is up

System is going to be down
  Info: memory module is down
  Info: timer module is down
  Info: memory module is destroying
  Info: timer module is destroying
root@ubuntu:/Wood_Work/LIYAO_MTJH/21.1# 

结果一样，说明优化不影响结果，从结果看，优化时成功的！

	
	
