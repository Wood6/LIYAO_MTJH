//����ϸ���̼��ʼǣ�
//����ϵ㼰����
[root@localhost 11]# gdb test.out //���� test.out
(gdb) set args 12345 //���������в���Ϊ 12345
(gdb) start //��ʼִ�� test.out������ͣ�� main ����
(gdb) break test.c:37 //�� test.c �ĵ� 37 �д�����ϵ�
(gdb) info breakpoints //�鿴�ϵ���Ϣ
(gdb) continue //�ָ�ִ�У���һֱ���е��� 37 ��
(gdb) next
(gdb) print i //��ӡ i ��ֵ
$1 = 1
(gdb) set var i=100 //���� i ��ֵΪ 100
(gdb) print i
$2 = 100
(gdb) tbreak test.c:42 //�� 42 ���¶ϵ�
(gdb) continue //������ 42 �У��� func()�������ú����������
��
(gdb) jump 46 //���� func ����������46��ִ��
main() : end... //��������������
Program exited normally.
(gdb) quit


//�ں������¶ϵ�
[root@localhost 11]# gdb test.out
(gdb) start
(gdb) break func //�� func ������ϵ�
(gdb) info breakpoints
(gdb) continue //ִ���� func ������ڴ�
(gdb) return //�� func �����з���


//����Ӳ���ϵ�
[root@localhost 11]# gdb test.out
(gdb) start
(gdb) show can-use-hw-watchpoints //�鿴�Ƿ�֧�ֵ�Ӳ���ϵ�
(gdb) hbreak func //�� func ������Ӳ���ϵ�
(gdb) info breakpoints //�鿴�ϵ���Ϣ(gdb) continue //���е� func ��������ڴ�
(gdb) print g_pointer //�鿴 g_pointer ��ֵ��Ϊ NULL��
(gdb) set var g_pointer=(int*)malloc(sizeof(int)) //���� g_pointer
(gdb) print g_pointer //�鿴 g_pointer ��ֵ������Ϊ 04a008��
(gdb) continue //�������У�������������
(gdb) quit