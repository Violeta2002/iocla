%include "../utils/printf32.asm"

%define NUM_FIBO 10

section .text

extern printf
global main
main:
    mov ebp, esp
    mov eax, 0
    mov ebx, 1
    mov ecx, NUM_FIBO
    dec ecx
    push eax

fibonacci:
    xor edx, edx
    add edx, eax
    add edx, ebx
    push edx
    mov ebx, eax
    mov eax, edx
    loop fibonacci

    mov ecx, NUM_FIBO
print:
    mov eax, dword [esp + (ecx - 1) * 4]
    PRINTF32 `%d \x0`, eax
    dec ecx
    cmp ecx, 0
    ja print

    PRINTF32 `\n\x0`
    mov esp, ebp
    xor eax, eax
    ret
