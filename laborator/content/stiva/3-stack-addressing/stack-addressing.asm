%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands (use direct addressing of memory. Hint: esp)
    mov ecx, NUM
push_nums:
    push ecx
    sub esp, 4
    mov dword[esp], ecx
    loop push_nums


    sub esp, 4
    mov dword[esp], 0

    sub esp, 4
    mov dword[esp], "mere"

    sub esp, 4
    mov dword[esp], "are "

    sub esp, 4
    mov dword[esp], "Ana "
    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above
 xor ebx, ebx
    mov ebx, esp

    xor ecx, ecx
    mov ecx, ebp
    sub ecx, esp

print: 
    cmp ecx, 0
    je out_print
    PRINTF32 `%p \x0`, ebx
    PRINTF32 `%hhu\n\x0`, byte[ebx]
    add ebx, 1
    sub ecx, 1
    jmp print
    ; TODO 3: print the string
out_print: 

    xor ebx, ebx
    mov ebx, esp

    xor ecx, ecx
    mov ecx, ebp
    sub ecx, esp

print_string:
     cmp ecx, 0
    je out__print_string
    xor eax, eax
    mov al, byte[ebx]
    cmp eax, 0
    je out__print_string
    PRINTF32 `%c\x0`, byte[ebx]
    add ebx, 1
    sub ecx, 1
    jmp print_string

    ; TODO 4: print the array on the stack, element by element.
out__print_string:

 add ebx, 4
    xor ecx, ecx
    mov ecx, NUM

PRINTF32 `\n\x0`

print_array:
    cmp ecx, 0
    je out_print_array
    PRINTF32 `%hhu \x0`, byte[ebx]
    add ebx, 4
    sub ecx, 1
    jmp print_array

out_print_array:
    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
