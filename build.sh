#!/bin/sh

mkdir output
make htc_pico_defconfig
schedtool -B -n 1 -e ionice -n 1 make -j `cat /proc/cpuinfo | grep "^processor" | wc -l`
make >&1 | tee ./output/log.txt
mv ./arch/arm/boot/zImage ./output
find ./ -name "*.ko" -exec mv {} ./output \;
echo "done, please check your output folder"
