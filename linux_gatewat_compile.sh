#!/bin/sh
cd ./build
rm -r *
cmake -DCMAKE_TOOLCHAIN_FILE=../arm-linux-gnueabihf.cmake ..
make
rm /home/danneil/items/nfs/ubuntu_rootfs/home/danneil/Linux_Gateway/Linux_Gateway_master
cp ./bin/Linux_Gateway_master /home/danneil/items/nfs/ubuntu_rootfs/home/danneil/Linux_Gateway
cd ..