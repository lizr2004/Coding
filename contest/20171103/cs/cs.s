	.file	"cs.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.globl	n
	.bss
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.globl	m
	.align 4
	.type	m, @object
	.size	m, 4
m:
	.zero	4
	.globl	sx
	.align 4
	.type	sx, @object
	.size	sx, 4
sx:
	.zero	4
	.globl	sy
	.align 4
	.type	sy, @object
	.size	sy, 4
sy:
	.zero	4
	.globl	ex
	.align 4
	.type	ex, @object
	.size	ex, 4
ex:
	.zero	4
	.globl	ey
	.align 4
	.type	ey, @object
	.size	ey, 4
ey:
	.zero	4
	.globl	ans
	.data
	.align 4
	.type	ans, @object
	.size	ans, 4
ans:
	.long	1061109567
	.globl	realdep
	.align 4
	.type	realdep, @object
	.size	realdep, 4
realdep:
	.long	1061109567
	.globl	arr
	.bss
	.align 32
	.type	arr, @object
	.size	arr, 262144
arr:
	.zero	262144
	.globl	vis
	.align 32
	.type	vis, @object
	.size	vis, 262144
vis:
	.zero	262144
	.section	.rodata
	.align 32
	.type	_ZL3ru1, @object
	.size	_ZL3ru1, 32
_ZL3ru1:
	.long	-1
	.long	-1
	.long	-1
	.long	0
	.long	0
	.long	1
	.long	1
	.long	1
	.align 32
	.type	_ZL3ru2, @object
	.size	_ZL3ru2, 32
_ZL3ru2:
	.long	-1
	.long	0
	.long	1
	.long	-1
	.long	1
	.long	-1
	.long	0
	.long	1
	.section	.text._Z4readRi,"axG",@progbits,_Z4readRi,comdat
	.weak	_Z4readRi
	.type	_Z4readRi, @function
_Z4readRi:
.LFB1021:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	$0, (%rax)
	movl	$1, -4(%rbp)
	call	getchar
	movb	%al, -5(%rbp)
.L5:
	cmpb	$47, -5(%rbp)
	jle	.L2
	cmpb	$57, -5(%rbp)
	jle	.L3
.L2:
	cmpb	$45, -5(%rbp)
	jne	.L4
	movl	$-1, -4(%rbp)
.L4:
	call	getchar
	movb	%al, -5(%rbp)
	jmp	.L5
.L3:
	cmpb	$47, -5(%rbp)
	jle	.L6
	cmpb	$57, -5(%rbp)
	jg	.L6
	movq	-24(%rbp), %rax
	movl	(%rax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movsbl	-5(%rbp), %eax
	addl	%edx, %eax
	leal	-48(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	call	getchar
	movb	%al, -5(%rbp)
	jmp	.L3
.L6:
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	imull	-4(%rbp), %eax
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1021:
	.size	_Z4readRi, .-_Z4readRi
	.text
	.globl	_Z3dfsiiii
	.type	_Z3dfsiiii, @function
_Z3dfsiiii:
.LFB1022:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	ex(%rip), %eax
	cmpl	%eax, -20(%rbp)
	jne	.L9
	movl	ey(%rip), %eax
	cmpl	%eax, -24(%rbp)
	jne	.L9
	movl	ans(%rip), %eax
	cmpl	-28(%rbp), %eax
	jle	.L10
	movl	-28(%rbp), %eax
	movl	%eax, ans(%rip)
.L10:
	movl	-32(%rbp), %eax
	movl	%eax, realdep(%rip)
	movl	ans(%rip), %eax
	cmpl	-28(%rbp), %eax
	jne	.L21
	leaq	-32(%rbp), %rax
	movl	$realdep, %esi
	movq	%rax, %rdi
	call	_ZSt3minIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	%eax, realdep(%rip)
	jmp	.L21
.L9:
	movl	$0, -12(%rbp)
.L20:
	cmpl	$7, -12(%rbp)
	jg	.L8
	movl	-12(%rbp), %eax
	cltq
	movl	_ZL3ru1(,%rax,4), %edx
	movl	-20(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -8(%rbp)
	movl	-12(%rbp), %eax
	cltq
	movl	_ZL3ru2(,%rax,4), %edx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	n(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jg	.L22
	cmpl	$0, -8(%rbp)
	jle	.L22
	movl	m(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L22
	cmpl	$0, -4(%rbp)
	jle	.L22
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$arr, %rax
	movzbl	(%rax), %eax
	cmpb	$48, %al
	je	.L23
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$vis, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L24
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$vis, %rax
	movb	$1, (%rax)
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$arr, %rax
	movzbl	(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$9, %rcx
	addq	%rcx, %rax
	addq	$arr, %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	jne	.L18
	movl	-32(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-28(%rbp), %edx
	movl	-4(%rbp), %esi
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	_Z3dfsiiii
	jmp	.L19
.L18:
	movl	-32(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-28(%rbp), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %esi
	movl	-8(%rbp), %eax
	movl	%eax, %edi
	call	_Z3dfsiiii
.L19:
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$vis, %rax
	movb	$0, (%rax)
	jmp	.L15
.L22:
	nop
	jmp	.L15
.L23:
	nop
	jmp	.L15
.L24:
	nop
.L15:
	addl	$1, -12(%rbp)
	jmp	.L20
.L21:
	nop
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1022:
	.size	_Z3dfsiiii, .-_Z3dfsiiii
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"cs.in"
.LC2:
	.string	"%s"
.LC3:
	.string	"%c "
.LC4:
	.string	""
.LC5:
	.string	"%d %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1023:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	movl	$.LC0, %esi
	movl	$.LC1, %edi
	call	freopen
	movl	$n, %edi
	call	_Z4readRi
	movl	$m, %edi
	call	_Z4readRi
	movl	$sx, %edi
	call	_Z4readRi
	movl	$sy, %edi
	call	_Z4readRi
	movl	$ex, %edi
	call	_Z4readRi
	movl	$ey, %edi
	call	_Z4readRi
	movl	$1, -12(%rbp)
.L27:
	movl	n(%rip), %eax
	cmpl	%eax, -12(%rbp)
	jg	.L26
	movl	-12(%rbp), %eax
	cltq
	salq	$9, %rax
	addq	$arr, %rax
	addq	$1, %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	addl	$1, -12(%rbp)
	jmp	.L27
.L26:
	movl	$1, -8(%rbp)
.L31:
	movl	n(%rip), %eax
	cmpl	%eax, -8(%rbp)
	jg	.L28
	movl	$1, -4(%rbp)
.L30:
	movl	m(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jg	.L29
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$9, %rdx
	addq	%rdx, %rax
	addq	$arr, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
	jmp	.L30
.L29:
	movl	$.LC4, %edi
	call	puts
	addl	$1, -8(%rbp)
	jmp	.L31
.L28:
	movl	sy(%rip), %esi
	movl	sx(%rip), %eax
	movl	$1, %ecx
	movl	$0, %edx
	movl	%eax, %edi
	call	_Z3dfsiiii
	movl	ans(%rip), %edx
	movl	realdep(%rip), %eax
	movl	%eax, %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1023:
	.size	main, .-main
	.section	.text._ZSt3minIiERKT_S2_S2_,"axG",@progbits,_ZSt3minIiERKT_S2_S2_,comdat
	.weak	_ZSt3minIiERKT_S2_S2_
	.type	_ZSt3minIiERKT_S2_S2_, @function
_ZSt3minIiERKT_S2_S2_:
.LFB1024:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L34
	movq	-16(%rbp), %rax
	jmp	.L35
.L34:
	movq	-8(%rbp), %rax
.L35:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1024:
	.size	_ZSt3minIiERKT_S2_S2_, .-_ZSt3minIiERKT_S2_S2_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1025:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L38
	cmpl	$65535, -8(%rbp)
	jne	.L38
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L38:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1025:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_n, @function
_GLOBAL__sub_I_n:
.LFB1026:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1026:
	.size	_GLOBAL__sub_I_n, .-_GLOBAL__sub_I_n
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_n
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
