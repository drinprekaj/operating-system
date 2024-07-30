# Makefile

# The cross-compiler to use
CC := i686-elf-gcc
AS := i686-elf-as

# Directories
SRCDIR := src
OBJDIR := obj
BINDIR := bin

# Files
KERNEL := $(BINDIR)/kernel.bin
BOOT := $(SRCDIR)/boot.asm
KERNEL_SRC := $(SRCDIR)/kernel.c
KERNEL_OBJ := $(OBJDIR)/kernel.o

# Build the kernel
all: $(KERNEL)

$(KERNEL): $(KERNEL_OBJ)
    $(CC) -T linker.ld -o $@ -ffreestanding -nostdlib $^ -lgcc

$(KERNEL_OBJ): $(KERNEL_SRC)
    mkdir -p $(OBJDIR)
    $(CC) -c $< -o $@ -ffreestanding -O2 -Wall -Wextra

# Clean up
clean:
    rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
