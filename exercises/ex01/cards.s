	.file	"cards.c"
	.text
	.globl	update_counter
	.type	update_counter, @function
update_counter:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$2, -8(%rbp)
	jle	.L2
	cmpl	$6, -8(%rbp)
	jg	.L2
	addl	$1, -4(%rbp)
	jmp	.L3
.L2:
	cmpl	$10, -8(%rbp)
	jne	.L3
	subl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	update_counter, .-update_counter
	.section	.rodata
.LC0:
	.string	"Enter the card_name: "
.LC1:
	.string	"%2s"
	.align 8
.LC2:
	.string	"I don't understand that value!"
	.text
	.globl	get_val
	.type	get_val, @function
get_val:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -24(%rbp)
.L14:
	movl	$0, -20(%rbp)
	movl	$.LC0, %edi
	call	puts
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movzbl	-16(%rbp), %eax
	movsbl	%al, %eax
	subl	$65, %eax
	cmpl	$23, %eax
	ja	.L6
	movl	%eax, %eax
	movq	.L8(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L8:
	.quad	.L7
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L9
	.quad	.L9
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L9
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L6
	.quad	.L17
	.text
.L9:
	movl	$10, -20(%rbp)
	jmp	.L11
.L7:
	movl	$11, -20(%rbp)
	jmp	.L11
.L6:
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	atoi
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jle	.L13
	cmpl	$10, -20(%rbp)
	jle	.L11
.L13:
	movl	$.LC2, %edi
	call	puts
	jmp	.L12
.L11:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	update_counter
	movl	%eax, -24(%rbp)
	jmp	.L12
.L17:
	nop
.L12:
	movzbl	-16(%rbp), %eax
	cmpb	$88, %al
	jne	.L14
	movl	-24(%rbp), %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L16
	call	__stack_chk_fail
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	get_val, .-get_val
	.section	.rodata
.LC3:
	.string	"%i"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %eax
	call	get_val
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
