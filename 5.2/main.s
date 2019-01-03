	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"test of macro definition"
.LC1:
	.string	"TEST = %s\n"
	.text
	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.globl	g_global
	.bss
	.align 4
	.type	g_global, @object
	.size	g_global, 4
g_global:
	.zero	4
	.globl	g_test
	.data
	.align 4
	.type	g_test, @object
	.size	g_test, 4
g_test:
	.long	1
	.section	.rodata
.LC2:
	.string	"&g_global = %p\n"
.LC3:
	.string	"&g_test = %p\n"
.LC4:
	.string	"&func =%p\n"
.LC5:
	.string	"&main = %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	call	func
	movl	$g_global, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$g_test, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$func, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	$main, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
