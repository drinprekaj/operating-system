[bits 16]
[org 0x7C00]

section .text
    ; Bootloader code

    ; Set up segments
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; Load kernel from disk to memory address 0x1000
    mov ah, 0x02        ; BIOS read sector function
    mov al, 1           ; Read one sector
    mov ch, 0           ; Cylinder number
    mov dh, 0           ; Head number
    mov cl, 2           ; Sector number (1-based, adjust as needed)
    mov dl, 0x80        ; Boot drive (0x80 for first HDD)

    mov bx, 0x1000      ; Destination address (where kernel will be loaded)
    int 0x13            ; BIOS interrupt for disk operations

    jc disk_error       ; Check for error
    jmp 0x1000:0x0000   ; Jump to the kernel entry point

disk_error:
    ; Handle disk read error (print error message or halt)

    cli
    hlt

times 510-($-$$) db 0   ; Pad the bootloader to 510 bytes
dw 0xAA55               ; Boot signature
