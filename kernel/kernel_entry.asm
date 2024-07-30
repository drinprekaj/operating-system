[bits 32]

section .text
global kernel_start

kernel_start:
    ; Kernel entry point

    ; Set up stack
    mov esp, stack_top

    ; Initialize segments
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Call kernel_main function
    call kernel_main

    ; Hang the system if kernel_main returns
    cli
    hlt

section .bss
align 4
stack_bottom equ 0x100000   ; 1 MB
stack_top equ stack_bottom - 4096

section .data
align 4
kernel_stack resb 4096      ; 4 KB kernel stack
