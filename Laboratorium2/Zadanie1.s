	.file	"Zadanie1.c"
	.text
	.globl	zawiera
	.def	zawiera;	.scl	2;	.type	32;	.endef
	.seh_proc	zawiera
zawiera:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	jmp	.L2
.L8:
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, -16(%rbp)
	jmp	.L3
.L5:
	addq	$1, -8(%rbp)
	addq	$1, -16(%rbp)
.L3:
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L4
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L4
	movq	-8(%rbp), %rax
	movzbl	(%rax), %edx
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	%al, %dl
	je	.L5
.L4:
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L6
	movl	$1, %eax
	jmp	.L7
.L6:
	addq	$1, 16(%rbp)
.L2:
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L8
	movl	$0, %eax
.L7:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "test.txt\0"
.LC2:
	.ascii "\12Podaj slowo do wyszukania: \0"
.LC3:
	.ascii "%49s\0"
.LC4:
	.ascii "%s\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$208, %rsp
	.seh_stackalloc	208
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	fopen
	movq	%rax, -8(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-176(%rbp), %rax
	leaq	.LC3(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	jmp	.L10
.L11:
	leaq	-176(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rax, %rcx
	call	zawiera
	testl	%eax, %eax
	je	.L10
	leaq	-112(%rbp), %rax
	leaq	.LC4(%rip), %rcx
	movq	%rax, %rdx
	call	printf
.L10:
	movq	-8(%rbp), %rdx
	leaq	-112(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L11
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	movl	$0, %eax
	addq	$208, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
