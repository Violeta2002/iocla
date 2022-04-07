%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua numere se gasesc in eax si ebx
    mov eax, 4
    mov ebx, 1
    cmp eax, ebx 
    jb print
    cmp eax, ebx
    jns min

print:
    PRINTF32 `%d\n\x0`, eax ; afiseaza minimul
    ret

min: 
    xchg eax, ebx
    jmp print

