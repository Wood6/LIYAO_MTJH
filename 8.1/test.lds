SECTIONS
{
	.text 0x2000000 :
	{
		*(.text)
	}
	
	. = 0x8000000;
	S = .;
	
	.data 0x3000000 :
	{
		*(.data)
	}
	
	.bss :
	{
		*(.bss)
	}
}
