#! /bin/bash

# Quiten el comentario del OS que usen
# Linux
clear
# cls

# Si tienen terminal que no borra la consola usen esto para ver
# donde empezo el input
printf "\n---start---\n"

#define el test file a usar
test=testFiles/test1.txt

# Corre el programa solo si se complila correctamente
# g++ -std=c++11 main.cpp -o main.out
g++ -std=c++11 main.cpp -o main.out && ./main.out < $test
