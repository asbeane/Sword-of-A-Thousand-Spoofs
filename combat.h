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

/**
 * combat
 * This is the real reason to include this header.
 * Given a Player object and room number, executes a battle between
 * the player and a generated enemy. The enemy is generated internally
 * based on the reported room number. Higher room numbers generate stronger
 * and more capable enemies.
 *
 * Every part of the combat scenario is handled by calling this one function.
 * Selecting an enemy, displaying output, getting input from the player on
 * the player's turn, performing the result of the player and enemies attacks, etc.
 *
 * Please note that the cutoffs for determining at which room number to begin
 * generating a stronger enemy are hardcoded into the function because the
 * setup of the dungeon for this program was also hardcoded. IF THIS EVER CHANGES
 * THEN THE CUTOFF VALUES IN THE "createEnemy" HELPER FUNCTION WILL NEED TO BE
 * CHANGED.
 *
 * The return value of this function indicates the outcome of the battle.
 *      returns true if the player wins
 *      returns false if the player dies
 **/
bool combat(Player &player, int room);

#endif // COMBAT_H
