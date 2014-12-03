#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "inventoryClasses.h"
using namespace std;

class Player
{
private:
    int MaxHP;
    int currentHP;
    int attack;
    int defense;
    //Inventory inv;
    Item_Weapon equipped_weapon;
    Item_Armor equipped_armor;
public:
    Player(int hp, int attk, int def);
    int getMaxHP();
    void setMaxHP(int value);
    int getCurrentHP();
    void setCurrentHP(int value);
    int getAttack();
    int getDefense();
    void equipWeapon(Item_Weapon& weap);
    void equipArmor(Item_Armor& arm);
    //void outputInventory();
    friend ostream& operator<<(ostream& out, const Player& player);
};
#endif // PLAYER_H
