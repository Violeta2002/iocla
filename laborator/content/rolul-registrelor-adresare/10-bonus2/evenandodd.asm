%include "../utils/printf32.asm"

%define ARRAY_SIZE  6

section .data
    numbers dd 1, 3, 4, 6, 8, 9
    print_format_even db "Even numbers ", 0
    print_format_odd db "Odd numbers ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    xor eax, eax
    xor edx, edx
    xor ebx, ebx
    mov ecx, ARRAY_SIZE

array_elements:
    mov eax, dword [numbers + 4*(ecx - 1)]
    and eax, 1
    cmp eax, 0
    je even
    inc edx
    loop array_elements
    jmp print

even:
    inc ebx
    dec ecx
    jmp array_elements

print:
    PRINTF32 `%s\x0`, print_format_even
    PRINTF32 `%d\n\x0`, ebx
    PRINTF32 `%s\x0`, print_format_odd
    PRINTF32 `%d\n\x0`, edx

    leave 
    ret

