不带优化选项编译：gcc -g device.c main.c -o main-NoOptimize.out -lpthread
带优化选项编译：gcc -O3 -g device.c main.c -o main-Optimize.out -lpthread

./main-NoOptimize.out  执行是期望结果
./main-Optimize.out 执行是期望结果


root@ubuntu:/Wood_Work/LIYAO_MTJH/17.2# ./main-Optimize.out 
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
init_device() - device status : g_ready = 1
main() - launching device : g_ready = 1
main() - device status : g_ready = 1
root@ubuntu:/Wood_Work/LIYAO_MTJH/17.2# ./main-NoOptimize.out 
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
main() - launching device : g_ready = 0
init_device() - device status : g_ready = 1
main() - launching device : g_ready = 1
main() - device status : g_ready = 1



		  
	
