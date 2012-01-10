// monitor.h -- Defines the interface for monitor.h
// From JamesM's kernel development tutorials.

#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

// Write a single character out to the screen.
void monitor_put(char c);

// Clear the screen to all black.
void monitor_clear();

// Output a null-terminated ASCII string to the monitor.
void monitor_write(const char *c);

// Move the cursor to the next line
void monitor_newline();

// Output a number to the screen in hexadecimal notation.
void monitor_write_hex(u32int n);

// Output a number to the screen in decimal notation.
void monitor_write_dec(u32int n);

#endif // MONITOR_H
