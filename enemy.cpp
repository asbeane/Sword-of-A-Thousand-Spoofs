#include <string>
#include <cstdlib>
#include "enemy.h"
#include "inventoryClasses.h"
#include "combat.h"

using namespace std;

/********************************
 *      ENEMY FUNCTIONS         *
 ********************************/
Enemy::Enemy(string _name, int hp, int attk, int def)
{
    name = _name;
    MaxHP = hp;
    currentHP = hp;
    attack = attk;
    defense = def;
}

string Enemy::getName()
{
    return name;
}
int Enemy::getMaxHP()
{
    return MaxHP;
}

int Enemy::getCurrentHP()
{
    return currentHP;
}

void Enemy::setCurrentHP(int value)
{
    currentHP = value;
    if(currentHP < 0)
    {
        currentHP = 0;
    }
    if(currentHP > MaxHP)
    {
        currentHP = MaxHP;
    }
}

int Enemy::getAttack()
{
    return attack;
}

int Enemy::getDefense()
{
    return defense;
}

//generate random option between 1 and 2, corresponding to weak attack or strong attack
Action Enemy::getCombatChoice(struct Cooldowns &cds)
{
    if(cds.heavy)
    {
        cds.heavy = 0;
        return WEAKATTACK; //can only weak attack when heavy attack is on cooldown
    }
    return (Action)((rand() % 2) + 1);
}

/********************************
 *  STRONGERENEMY FUNCTIONS     *
 ********************************/

StrongerEnemy::StrongerEnemy(string _name, int hp, int attk, int def)
: Enemy(_name, hp, attk, def), equipped_weapon("default_weapon", 0), equipped_armor("default_armor", 0)
{
    Item_Weapon* weap = pickRandWeapon(false);
    Item_Armor* arm = pickRandArmor(false);
    equipped_weapon = *weap;
    equipped_armor = *arm;
    delete weap;
    delete arm;
}

int StrongerEnemy::getAttack()
{
    return attack + equipped_weapon.getWeaponDamage();
}

int StrongerEnemy::getDefense()
{
    return defense + equipped_armor.getArmorRating();
}

//generate random option between 1 and 3. this means a StrongerEnemy can dodge as well as attack.
Action StrongerEnemy::getCombatChoice(struct Cooldowns &cds)
{
    int randNum;

    if(cds.heavy) //if heavy attack (option 2) is on cooldown, ensure that choice is either 1 or 3
    {
        do
        {
            randNum = (rand() % 3) + 1;
        }while(randNum == 2);
        cds.heavy = 0;

    }
    else if(cds.dodge) //if dodge (option 3) is on cooldown, generate a random number between 1 and 2
    {
        randNum = (rand() % 2) + 1;
        cds.dodge = 0;
    }
    else
    {
        randNum = (rand() % 3) + 1;
    }

    return (Action)randNum;
}

/********************************
 *      BESTENEMY FUNCTIONS     *
 ********************************/

BestEnemy::BestEnemy(string _name, int hp, int attk, int def)
: StrongerEnemy(_name, hp, attk, def)
{
}

Action BestEnemy::getCombatChoice(struct Cooldowns &cds)
{
    int randNum;

    if(cds.heavy) //if heavy attack (option 2) is on cooldown, ensure that choice is either 1, 3, or 4
    {
        do
        {
            randNum = (rand() % 4) + 1;
        }while(randNum == 2);
        cds.heavy = 0;

    }
    else if(cds.dodge) //if dodge (option 3) is on cooldown, ensure that choice is either 1, 2, or 4
    {
        do
        {
            randNum = (rand() % 4) + 1;
        }while(randNum == 3);
        cds.dodge = 0;
    }
    else if(cds.block)
    {
        randNum = (rand() % 3) + 1; //option between 1 and 3 if option 4 is on cooldown
        cds.block = 0;
    }
    else
    {
        randNum = (rand() % 4) + 1;
    }

    return (Action)randNum;
}
