.extern bootloader_entry
.global _start

.section .text
_start:
    movq $0x7C00, %rsp

    call bootloader_entry

hang:
    jmp hang
