ENTRY(mymain) /* 指定入口函数为 mymain */

SECTIONS
{
    /* 将所有目标文件中的.text和.rodata段合并进入可执行程序中的.text段 */
    .text 0x08048000 + SIZEOF_HEADERS : 
    {
        *(.text)    
        *(.rodata)  /* 本例中，“ liyao test!\n 字符串位于.rodata段” */
    }
    
    /DISCARD/ : 
    {
        *(*)        /* 放弃所有目标文件中除.text和.rodata之外的其它段 */
    }
}