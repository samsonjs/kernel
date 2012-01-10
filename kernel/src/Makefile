SOURCES=boot.o main.o common.o monitor.o descriptor_tables.o isr.o interrupt.o \
        gdt.o timer.o kheap.o paging.o ordered_array.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld
ASFLAGS=-f elf

all: $(SOURCES) link

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	yasm $(ASFLAGS) $<
