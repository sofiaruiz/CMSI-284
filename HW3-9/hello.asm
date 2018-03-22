//Lauren Alvarez and Sofia Ruiz

global start

section .text
start:
    mov rax, 0x2000004
    mov rdi, 1
    mov rsi, message
    mov rdx, 15
    syscall

    mov rax, 0x2000001
    mov rdi, 0
    syscall

    section .data
message: db '最近怎么样', 10
