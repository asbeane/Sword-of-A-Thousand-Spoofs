#ifndef COMBAT_H
#define COMBAT_H

#include "player.h"
using namespace std;

enum combatmoves{WEAKATTACK = 1, HEAVYATTACK = 2, DODGE = 3, BLOCK = 4};
typedef enum combatmoves Action;

struct Cooldowns
{
    int heavy;
    int dodge;
    int block;
    Cooldowns()
    {
        heavy = 0;
        dodge = 0;
        block = 0;
    }
};

int combat(Player &player);
#endif // COMBAT_H
