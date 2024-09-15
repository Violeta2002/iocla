%include "../utils/printf32.asm"

section .data
    num dd 100
    print_format1 db "Sum(", 0
    print_format2 db "): ", 0

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, [num]     ; Use ecx as counter for computing the sum.
    xor eax, eax
    xor ebx, ebx       ; Use ebx to store the sum. Start from 0.

add_to_square_sum:
    mov edx, ecx
    imul edx, edx
    add ebx, edx
    loop add_to_square_sum

    mov ecx, [num]
    PRINTF32 `%s\x0`, print_format1
    PRINTF32 `%u\x0`, ecx
    PRINTF32 `%s\x0`, print_format2
    PRINTF32 `%u\n\x0`, ebx

    leave
    ret