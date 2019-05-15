#!/bin/bash

gcc -o 3x3division.exe 3x3division.c &&
./3x3division.exe > 3x3gamelog.txt &&
gcc -o 5x5division.exe 5x5division.c &&
./5x5division.exe > 5x5gamelog.txt