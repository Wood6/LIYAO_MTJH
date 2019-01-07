// watch.c
// gcc -g watch.c -o watch.out -lpthread
[root@localhost 12]# gdb watch.out
(gdb) start(gdb) watch g_var //�����ݶϵ�
(gdb) info breakpoints //�鿴���ݶϵ�
(gdb) continue //����ִ�е����ݶϵ㴦
Continuing.
[New Thread 0xb7ff5b70 (LWP 4906)]
g_var = 0
g_var = 0
g_var = 0
g_var = 0
g_var = 0
[Switching to Thread 0xb7ff5b70 (LWP 4906)]
Hardware watchpoint 2: g_var //�ϵ㱻����
Old value = 0 //g_var ԭ�е�ֵ
New value = 1 //g_var �µ�ֵ
thread_func (args=0x0) at watch.c:13 //g_var �� watch.c �ĵ� 13 �д��������ģ���12��ִ����Ÿı䣬���Բŵ�13�л��⵽����ı䣡
(gdb) print g_var //��ӡ g_var ��ֵ
(gdb) print /a &g_var //��ӡ g_var �ĵ�ַ
$2 = 0x8049818 <g_var>
(gdb) x /4bx &g_var //�鿴��&g_var ��ַ��ʼ���� 4 �ֽ�����
0x8049818 <g_var>: 0x01 0x00 0x00 0x00
(gdb) x /1bx 0x804981 //�鿴��&g_var ��ַ��ʼ���� 1 �ֽ�����
0x8049818 <g_var>: 0x01
(gdb) continue
(gdb) quit



// frame.c
[root@localhost 12]# gdb frame.out
(gdb) start
(gdb) break sum if n==0 //�� sum �������������ϵ㣨�� n==0 ʱ��
(gdb) info breakpoints //�鿴�ϵ���Ϣ
(gdb) continue //ִ�е��ϵ㴦(gdb) backtrace //�鿴��������ջ
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
(gdb) info args //�鿴��ǰ sum �����Ĳ���ֵ��n==0��
(gdb) frame 7 //�л������Ϊ 7 ��ջ�崦
(gdb) info args //�鿴��ǰ sum �����Ĳ���ֵ��n==7��
(gdb) info locals //�鿴�ֲ�������ֵ
(gdb) frame 0 //�л����� 0 ջ�崦
(gdb) info registers //�鿴�Ĵ�����ֵ
(gdb) info frame //�鿴ջ����Ϣ
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
(gdb) shell gcc -g tricks.c -o tricks.out //���� shell ���б���(gdb) shell cat tricks.c //���� shell �鿴 tricks.c ������
(gdb) file tricks.out //���� tricks.out
(gdb) start
(gdb) list tricks.c:18 //��ʾ tricks.c �� 18 �е�����
(gdb) set listsize 20 //���� list ��ʾ������Ϊ 20 �С�
(gdb) show listsize //�鿴 list ��ʾ��������
(gdb) break tricks.c:18
(gdb) continue
(gdb) display /d i //�����Զ���ӡ i ��ֵ���ϵ�ʱ���Զ���ӡ
(gdb) display /d i*i //�����Զ���ӡ i*i ��ֵ���ϵ�ʱ���Զ���ӡ
(gdb) display /a &i //�����Զ���ӡ i*i �ĵ�ַ
(gdb) continue
(gdb) undisplay //ȡ���Զ���ӡ
(gdb) whatis g_var //�鿴 g_var ������: type = int
(gdb) ptype g_var //�鿴 g_var �����ͣ��� whatis ���һ��
(gdb) whatis func //�鿴 func ������, type = int()
(gdb) ptype func //�鿴 func �����ͣ��� whatis ���һ��
(gdb) whatis struct ST //�鿴 struct ST ������:type = struct ST
(gdb) ptype struct ST //�鿴 struct ST �Ķ��壬Ҳ�ɲ鿴�� struct ST����ı�������
type = struct ST {
int i;
int j;
}
(gdb) info variables //�鿴���������еķ��ţ��� g_var
(gdb) info functions //�鿴���к������� func�� main
(gdb) quit