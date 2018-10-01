#!/bin/sh

arm-linux-gnueabi-gcc -shared -o libarm_socket.so -fPIC -c arm_socket.c
arm-linux-gnueabi-gcc client.c -larm_socket -L. -o client
arm-linux-gnueabi-gcc server.c -larm_socket -L. -o server
