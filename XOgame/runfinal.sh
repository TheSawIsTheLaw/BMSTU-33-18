#!/bin/bash

touch decider_gamelog.txt &&
gcc -o decider_division.exe decider_division.c &&
./decider_division.exe > decider_gamelog.txt