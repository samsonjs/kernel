// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials

#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{
    monitor_clear();
    monitor_write("Hello, world!");

    monitor_newline();
    monitor_write_dec(42);
    
    monitor_newline();
    monitor_write_hex(0xdeadbeef);
    
    return 0xdeadbeef;
}
