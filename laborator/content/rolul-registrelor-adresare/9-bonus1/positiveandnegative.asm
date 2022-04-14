%include "../utils/printf32.asm"

%define ARRAY_SIZE    10

section .data
    numbers dd 1, -1 ,3 ,-5, 7, 8, 4, 6 , -8, 2
    print_format_pos db "Number of positve elements ", 0
    print_format_neg db "Number of negative elements ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, ARRAY_SIZE
    xor eax, eax
    xor ebx, ebx
    xor edx, edx

array_elements:
    mov eax, dword [numbers + 4*(ecx - 1)]
    cmp eax, 0
    jg increment_pos
    inc ebx
    loop array_elements
    jmp print

increment_pos:
    inc edx
    dec ecx
    jmp array_elements

;increment_neg:
    ;inc ebx
    ;dec ecx
    ;jmp array_elements

print:
    PRINTF32 `%s\x0`, print_format_pos
    PRINTF32 `%d\n\x0`, edx
    PRINTF32 `%s\x0`, print_format_neg
    PRINTF32 `%d\n\x0`, ebx

    leave 
    ret
