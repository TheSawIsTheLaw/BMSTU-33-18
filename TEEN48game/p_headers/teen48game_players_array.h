#ifndef __TEEN48GAME_PLAYERS_ARRAY_H__
#define __TEEN48GAME_PLAYERS_ARRAY_H__

#include <inttypes.h>

#include "../p_headers/teen48game_player_romanov.h"
#include "../p_headers/teen48game_player_chernenko.h"
#include "../p_headers/teen48game_player_nitenko.h"
#include "../p_headers/teen48game_player_akhmetov.h"
#include "../p_headers/teen48game_player_aleksandrovich.h"
#include "../p_headers/teen48game_player_burtelov.h"
#include "../p_headers/teen48game_player_chelyadinov.h"
#include "../p_headers/teen48game_player_kononenko.h"
#include "../p_headers/teen48game_player_minenko.h"
#include "../p_headers/teen48game_player_prohorova.h"
#include "../p_headers/teen48game_player_saburov.h"
#include "../p_headers/teen48game_player_sukocheva.h"
#include "../p_headers/teen48game_player_sverdlov.h"
#include "../p_headers/teen48game_player_yakuba.h"

#define PLAYERS_COUNT 14 // заменить при добавлении, и заменить в call_players

char (*players_funcs[])(matrix_t *const buffer, int (*)(matrix_t *const, const char )) =
{

    teen48game_player_chernenko,
    teen48game_player_romanov,
    teen48game_player_nitenko,
    teen48game_player_akhmetov,
    teen48game_player_aleksandrovich,
    teen48game_player_burtelov,
    teen48game_player_chelyadinov,
    teen48game_player_kononenko,
    teen48game_player_minenko,
    teen48game_player_prohorova,
    teen48game_player_saburov,
    teen48game_player_sukocheva,
    teen48game_player_sverdlov,
    teen48game_player_yakuba
};

uint64_t players_time[PLAYERS_COUNT] = { 0 };

char players_names[PLAYERS_COUNT][N] =
{
    "Chernenko",
    "Romanov",
    "Nitenko",
    "Akhmetov",
    "Aleksandrovich",
    "Burtelov",
    "Chelyadinov",
    "Kononenko",
    "Minenko",
    "Prohorova",
    "Saburov", 
    "Sukocheva",
    "Sverdlov", 
    "Yakuba" 
};

#endif
