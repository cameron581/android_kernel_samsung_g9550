#!/bin/bash
export ARCH=arm64
export CROSS_COMPILE=../PLATFORM/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android-

mkdir out

make -C $(pwd) O=out -j8 ARCH=arm64 CROSS_COMPILE=$(pwd)/../PLATFORM/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android- KCFLAGS=-mno-android greatqlte_chn_hk_defconfig
make -C $(pwd) O=out -j8 ARCH=arm64 CROSS_COMPILE=$(pwd)/../PLATFORM/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9/bin/aarch64-linux-android- KCFLAGS=-mno-android


cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image


