#ifndef _TEENGAME48GAME_TO_STEP_H_

#define _TEENGAME48GAME_TO_STEP_H_

#include "../f_headers/teen48game_to_step.h"
#include <matrixgame.h>

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

int to_step(matrix_t *const field, const char key);

#endif