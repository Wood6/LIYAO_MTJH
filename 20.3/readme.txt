gcc -g *.c -o main.out -lpthread
root@ubuntu:/Wood_Work/LIYAO_MTJH/20.3# ./main.out 
I'm callback for t1.

root@ubuntu:/Wood_Work/LIYAO_MTJH/20.3# 
执行结果，只执行一次就终止了，因为定时器被销毁了


在main.c的回调函数中调用定时器销毁函数
timer.c 第53行：回调函数中已经将st指针释放，这里就会造成野指针形成，这也是没有防御性编程的影响