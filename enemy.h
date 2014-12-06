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
    virtual ~Enemy(){cout << "DESTROYING ENEMY\n";}
    string getName();
    int getMaxHP();
    int getCurrentHP();
    void setCurrentHP(int value);
    virtual int getAttack();
    virtual int getDefense();
    virtual Action getCombatChoice(struct Cooldowns &cds);
};

class StrongerEnemy: public Enemy
{
protected:
    Item_Weapon equipped_weapon;
    Item_Armor equipped_armor;
public:
    StrongerEnemy(string _name, int hp, int attk, int def);
    ~StrongerEnemy(){cout << "DESTROYING STRONGERENEMY\n";}
    int getAttack();
    int getDefense();
    Action getCombatChoice(struct Cooldowns &cds);
};

class BestEnemy: public StrongerEnemy
{
public:
    BestEnemy(string _name, int hp, int attk, int def);
    ~BestEnemy(){cout << "DESTROYING BESTENEMY\n";}
    Action getCombatChoice(struct Cooldowns &cds);
};
#endif // ENEMY_H
