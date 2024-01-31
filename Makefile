# Makefile

CC = gcc
AS = nasm
LD = ld
XORRISO = xorriso
QEMU = qemu-system-x86_64

CFLAGS = -m64 -ffreestanding -nostartfiles
ASFLAGS = -f elf64
LDFLAGS = -Ttext 0x7C00 --oformat binary

bootloader_and_program.bin: bootloader.asm main.c
	$(AS) $(ASFLAGS) bootloader.asm -o bootloader.o
	$(CC) $(CFLAGS) -c main.c -o my_program.o
	$(LD) $(LDFLAGS) -o $@ bootloader.o my_program.o

my_program.iso: bootloader_and_program.bin
	mkdir -p iso
	cp bootloader_and_program.bin iso/
	$(XORRISO) -as mkisofs -b bootloader_and_program.bin -no-emul-boot -boot-load-size 4 -o $@ iso/

run: my_program.iso
	$(QEMU) -cdrom $<

clean:
	rm -rf bootloader_and_program.bin my_program.o bootloader.o iso my_program.iso

