gdb 调试直观查看结构体内存模型：
(gdb) file main.out
Reading symbols from main.out...done.
(gdb) list 
7		int j : 9;
8		char c;
9		short t : 9;
10		short u : 9;
11		char d;
12	} s;
13	
14	int main(int argc, char* argv[])
15	{
16		int i = 0;
(gdb) 
17		int* p = (int*)&s;
18		
19		printf("sizeof = %d\n", sizeof(s));
20		
21		s.s = 0x1FF;
22		s.j = 0x1FF;
23		s.c = 0xFF;
24		s.t = 0x1FF;
25		s.u = 0x1FF;
26		s.d = 0xFF;
(gdb) 
27		
28		for(i=0; i<sizeof(s)/sizeof(*p); i++)
29		{
30			printf("%X\n",*p++);
31		}
32		
33		return 0;
34	}
35	/*
36	?3?
(gdb) break 27
Breakpoint 1 at 0x80484a9: file main.c, line 27.
(gdb) info breakpoints 
Num     Type           Disp Enb Address    What
1       breakpoint     keep y   0x080484a9 in main at main.c:27
(gdb) continue 
The program is not being run.
(gdb) start 
Temporary breakpoint 2 at 0x8048426: file main.c, line 16.
Starting program: /Wood_Work/LIYAO_MTJH/14.1/main.out 

Temporary breakpoint 2, main (argc=1, argv=0xbffff744) at main.c:16
16		int i = 0;
(gdb) continue 
Continuing.
sizeof = 12

Breakpoint 1, main (argc=1, argv=0xbffff744) at main.c:28
28		for(i=0; i<sizeof(s)/sizeof(*p); i++)
(gdb) print &s.s
$1 = (short *) 0x804a024 <s>
(gdb) x /12bt 0x804a024
0x804a024 <s>:	11111111	11111111	00000011	11111111	11111111	00000001	11111111	00000001
0x804a02c <s+8>:	11111111	00000000	00000000	00000000
(gdb) x /12bx 0x804a024
0x804a024 <s>:	0xff	0xff	0x03	0xff	0xff	0x01	0xff	0x01
0x804a02c <s+8>:	0xff	0x00	0x00	0x00
