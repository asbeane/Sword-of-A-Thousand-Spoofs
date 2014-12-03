#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "inventoryClasses.h"
#include "combat.h"
using namespace std;

class Enemy
{
protected:
    string name;
    int MaxHP;
    int currentHP;
    int attack;
    int defense;
public:
    Enemy(string _name, int hp, int attk, int def);
    string getName();
    int getMaxHP();
    int getCurrentHP();
    void setCurrentHP(int value);
    int getAttack();
    int getDefense();
    Action getCombatChoice(struct Cooldowns &cds);
};

class StrongerEnemy: public Enemy
{
protected:
    Item_Weapon equipped_weapon;
    Item_Armor equipped_armor;
public:
    StrongerEnemy(string _name, int hp, int attk, int def);
    int getAttack();
    int getDefense();
    Action getCombatChoice(struct Cooldowns &cds);
};

class BestEnemy: public StrongerEnemy
{
public:
    BestEnemy(string _name, int hp, int attk, int def);
    Action getCombatChoice(struct Cooldowns &cds);
};
#endif // ENEMY_H
