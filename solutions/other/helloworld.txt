.intel_syntax noprefix
.global _start

_start:
	mov     eax,    4
    xor     ebx,    ebx
    inc     ebx
    lea     ecx,    msg
    lea     edx,    lengths
    int     0x80
    xor     eax,    eax
    xor     ebx,    ebx
    inc     eax
    int     0x80
	
msg:
    .ascii  "Hello, World!\n"
    lengths = . - msg