#ifndef _TEENGAME48GAME_TO_STEP_H_

#define _TEENGAME48GAME_TO_STEP_H_

#define LOCAL_DEPLOY 0

#include "../f_headers/teen48game_to_step.h"

#if LOCAL_DEPLOY
#include "../../MATRIXgame/headers/matrixgame.h" 
#else
#include <matrixgame.h>
#endif

// Ключи
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'

// Коды возврата
#define OK 0
#define WRONG_DIMS 500
#define WRONG_KEY_ERROR 501
#define MOVE_ERROR 502
#define WRONG_ARGUMENT 503

int to_step(matrix_t *const field, const char key);

#endif