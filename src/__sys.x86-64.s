.global __syscall
.type __syscall, %function
__syscall:
	mov %rdi, %rax
	mov %rsi, %rdi
	mov %rdx, %rsi
	mov %rcx, %rdx
	mov %r8,  %r10
	mov %r9,  %r8
	mov 8(%rsp), %r9
	syscall
	ret
	.size __syscall,.-__syscall

.global _start
.type _start, %function
_start:
	popq %rdi
	movq %rsp, %rsi
	call __main
	.size _start,.-_start
