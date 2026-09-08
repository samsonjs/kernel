SOURCES=boot.o main.o common.o monitor.o descriptor_tables.o isr.o interrupt.o \
        gdt.o timer.o kheap.o paging.o ordered_array.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -fno-pie -fno-pic
LDFLAGS=-m elf_i386 -T link.ld
ASFLAGS=-f elf32

all: $(SOURCES) link

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
