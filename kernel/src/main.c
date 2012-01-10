// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials

#include "descriptor_tables.h"
#include "monitor.h"
#include "paging.h"
#include "timer.h"

int main(struct multiboot *mboot_ptr)
{
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    
    // Initialise the screen (by clearing it)
    monitor_clear();
    
    // Exercise kmalloc and kfree
    u32int a = kmalloc(8); // allocated via placement address

    initialise_paging();

    // allocated on the heap
    u32int b = kmalloc(8);
    u32int c = kmalloc(8);
    monitor_write("a: ");
    monitor_write_hex(a);
    monitor_write(", b: ");
    monitor_write_hex(b);
    monitor_write("\nc: ");
    monitor_write_hex(c);

    kfree(c);
    kfree(b);
    u32int d = kmalloc(12);
    monitor_write(", d: ");
    monitor_write_hex(d);
    monitor_newline();

    // Write out a sample string
    monitor_write("Hello, paging world!\n");
    
    // Write a number in decimal
    monitor_write_dec(42);
    monitor_newline();
    
    // Write a number in hex
    monitor_write("0x");
    monitor_write_hex(0xdeadbeef);
    monitor_newline();

    asm volatile("int $0x3");
    asm volatile("int $0x4");

//    asm volatile("sti");
//    init_timer(50);

    u32int *ptr = (u32int*)0xA0000000;
    u32int cause_a_page_fault = *ptr;
    
    return 0xdeadbeef;
}
