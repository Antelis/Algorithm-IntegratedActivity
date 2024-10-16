#! /bin/bash

# Quiten el comentario del OS que usen
# Linux
clear
# Windows
# cls

# Si tienen terminal que no borra la consola usen esto para ver
# donde empezo el input
printf "\n---start---\n"

# Corre el programa solo si se complila correctamente
#define el test file
test=test1.txt

g++ main.cpp -o main.out && ./main.out < $test