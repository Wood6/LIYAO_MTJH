1��ִ�����
	ulimit -c umlimited
	gcc -g main.c -o main.out
	dmesg core
	addr2line -f -e main.out 080483fa > result.txt

2����������˵����
	ulimit -c umlimited  shell����������ռ�õ���Դ��-c Ϊ����core�ļ������ֵ��umlimited��ʾ������
	ulimit -c 0   ���ƴ�СΪ0�����ر�����core�ļ�
	core�ļ���⣬���ļ���
	
	
