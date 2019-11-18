#ifndef _TEEN48GAME_TO_STEP_TESTS_H_

#define _TEEN48GAME_TO_STEP_TESTS_H_

#include <stdio.h>

#define LOCAL_DEPLOY 0

#if LOCAL_DEPLOY
// #include "../../MATRIXgame/headers/matrixgame.h"
#else
#include <matrixgame.h>
#endif

#include "../f_headers/teen48game_to_step.h"

#define INPUT_FILE "input.txt"
#define RESULT_FILE "result.txt"

// left
#define INPUT_1 "2 2 2 2 4 4 4 4 8 8 8 8 16 16 16 16"
#define RESULT_1 "4 4 0 0 8 8 0 0 16 16 0 0 32 32 0 0"

#define INPUT_2 "4 4 0 0 8 8 0 0 16 16 0 0 32 32 0 0"
#define RESULT_2 "8 0 0 0 16 0 0 0 32 0 0 0 64 0 0 0"

#define INPUT_3 "8 0 0 0 16 0 0 0 32 0 0 0 64 0 0 0"
#define RESULT_3 "8 0 0 0 16 0 0 0 32 0 0 0 64 0 0 0"

#define INPUT_4 "4 4 8 16 2 4 8 16 16 8 4 2 0 0 0 0"
#define RESULT_4 "8 8 16 0 2 4 8 16 16 8 4 2 0 0 0 0"

#define INPUT_5 "2 2 4 4 4 8 2 2 2 4 8 16 16 4 8 16"
#define RESULT_5 "4 8 4 8 4 2 4 8 32 4 8 16 0 0 0 0"

// right
#define INPUT_6 "2 2 2 2 4 4 4 4 8 8 8 8 16 16 16 16"
#define RESULT_6 "0 0 4 4 0 0 8 8 0 0 16 16 0 0 32 32"

#define INPUT_7 "0 0 4 4 0 0 8 8 0 0 16 16 0 0 32 32"
#define RESULT_7 "0 0 0 8 0 0 0 16 0 0 0 32 0 0 0 64"

#define INPUT_8 "0 0 0 8 0 0 0 16 0 0 0 32 0 0 0 64"
#define RESULT_8 "0 0 0 8 0 0 0 16 0 0 0 32 0 0 0 64"

#define INPUT_9 "16 8 4 4 16 8 4 2 2 4 8 16 0 0 0 64"
#define RESULT_9 "0 16 8 8 16 8 4 2 2 4 8 16 0 0 0 64"

#define INPUT_10 "2 4 4 4 8 2 2 2 4 8 16 16 4 8 16"
#define RESULT_10 "0 0 0 2 4 8 8 2 4 4 8 32 4 8 16"

// up

#define INPUT_11  "2 2 2 2\
                   4 4 4 4\
                   8 8 8 8\
                   16 16 16 16"

#define RESULT_11 "2 2 2 2\
                   4 4 4 4\
                   8 8 8 8\
                   16 16 16 16" 

#define INPUT_12  "2 2 2 2\
                   2 2 2 2\
                   2 2 2 2\
                   2 2 2 2"

#define RESULT_12 "4 4 4 4\
                   4 4 4 4\
                   0 0 0 0\
                   0 0 0 0" 

#define INPUT_13  "4 4 4 4\
                   4 4 4 4\
                   0 0 0 0\
                   0 0 0 0"

#define RESULT_13 "8 8 8 8\
                   0 0 0 0\
                   0 0 0 0\
                   0 0 0 0" 

#define INPUT_14  "4 2 16 0\
                   4 4 8 0\
                   8 8 4 0\
                   16 16 2 0"

#define RESULT_14 "8 2 16 0\
                   8 4 8 0\
                   16 8 4 0\
                   0 16 2 0" 

#define INPUT_15  "8\
                   16\
                   16\
                   8\
                   2\
                   2\
                   2\
                   4\
                   8\
                   8"

#define RESULT_15 "8\
                   32\
                   8\
                   4\
                   2\
                   4\
                   16\
                   0\
                   0\
                   0" 

// down

#define INPUT_16  "2 2 2 2\
                   4 4 4 4\
                   8 8 8 8\
                   16 16 16 16"

#define RESULT_16 "2 2 2 2\
                   4 4 4 4\
                   8 8 8 8\
                   16 16 16 16" 

#define INPUT_17  "2 2 2 2\
                   2 2 2 2\
                   2 2 2 2\
                   2 2 2 2"

#define RESULT_17 "0 0 0 0\
                   0 0 0 0\
                   4 4 4 4\
                   4 4 4 4" 

#define INPUT_18  "0 0 0 0\
                   0 0 0 0\
                   4 4 4 4\
                   4 4 4 4"

#define RESULT_18 "0 0 0 0\
                   0 0 0 0\
                   0 0 0 0\
                   8 8 8 8" 

#define INPUT_19  "4 2 16 0\
                   4 4 8 0\
                   8 8 4 0\
                   16 16 2 0"

#define RESULT_19 "0 2 16 0\
                   8 4 8 0\
                   8 8 4 0\
                   16 16 2 0" 

#define INPUT_20  "8\
                   16\
                   16\
                   8\
                   2\
                   2\
                   2\
                   4\
                   8\
                   8"

#define RESULT_20 "0\
                   0\
                   0\
                   8\
                   32\
                   8\
                   2\
                   4\
                   4\
                   16" 

// Negatives

#define INPUT_21  "8 16 8\
                   16 8 16\
                   2 4 2"

#define RESULT_21 "16 16 16\
                   32 32 32\
                   64 64 64"

#define INPUT_22  "8 16 32\
                   8 16 32\
                   8 16 32\
                   8 16 32"

#define RESULT_22 "8 16 32\
                   8 16 32\
                   8 16 32"

#define INPUT_23  "8 16 32 64\
                   8 16 32 64\
                   8 16 32 64"

#define RESULT_23 "8 16 32\
                   8 16 32\
                   8 16 32"

#define INPUT_24 ""
#define RESULT_24 ""

#define OK 0
#define ERRORS_DETECTED 1

#endif