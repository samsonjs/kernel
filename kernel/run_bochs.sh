#!/bin/sh

losetup /dev/loop0 floppy.img
bochs -f bochsrc
sleep 1
losetup -d /dev/loop0
