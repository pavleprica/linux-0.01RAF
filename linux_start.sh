#!/bin/bash
echo Starting...
qemu-system-i386 -hdb hd_oldlinux.img -fda Image -boot a
fi
