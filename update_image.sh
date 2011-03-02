#!/bin/sh

losetup /dev/loop0 floppy.img
mount /dev/loop0 /mnt
cp src/kernel /mnt/kernel
sleep 1
umount /mnt
losetup -d /dev/loop0
