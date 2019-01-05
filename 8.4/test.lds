MEMORY
{
	RAM0(WX) : ORIGIN = 0x8048000, LENGTH = 1024k
	RAM1(!x) : ORIGIN = 0x804a000, LENGTH = 256k
}

SECTIONS
{
	.text : {*(.text)} > RAM0   /*将代码段链接到RAM0存储区*/
	.data : {*(.data)} > RAM1   /*将数据段链接到RAM1存储区*/
	.bss  : {*(.bss)} > RAM1
}
