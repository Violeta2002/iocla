%include "../utils/printf32.asm"

section .data
    mystring db "This is my string", 0
    mylength db "String length is %d", 10, 0
section .text

extern puts
extern printf
global main

main:
    push ebp
    mov ebp, esp

    mov eax, mystring
    xor ecx, ecx
test_one_byte:
    mov bl, byte [eax]
    test bl, bl
    jne test_one_byte
    dec ecx
    push ecx
    push mylength
    call printf
    add esp, 8

;out:
    ;PRINTF32 `[PRINTF32]: %d\n[printf]: \x0`, ecx

    leave
    ret
