#!/bin/sh

gcc -shared -o libarm_socket.so -fPIC -c arm_socket.c
gcc client.c -larm_socket -L. -o client
gcc server.c -larm_socket -L. -o server
