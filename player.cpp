#include <iostream>
#include "inventoryClasses.h"
#include "player.h"

using namespace std;

Player::Player(int hp, int attk, int def): /*inv(),*/ equipped_weapon("Paper Sword       ", 0), equipped_armor("Torn Clothes      ", 0)
{
    MaxHP = hp;
    currentHP = hp;
    attack = attk;
    defense = def;
}

int Player::getMaxHP()
{
    return MaxHP;
}

void Player::setMaxHP(int value)
{
    MaxHP = value;
    if(MaxHP < 1)
    {
        MaxHP = 1;
    }
}

int Player::getCurrentHP()
{
    return currentHP;
}

void Player::setCurrentHP(int value)
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

int Player::getAttack()
{
    return attack + equipped_weapon.getWeaponDamage();
}

int Player::getDefense()
{
    return defense + equipped_armor.getArmorRating();
}

void Player::equipWeapon(Item_Weapon& weap)
{
    Item_Weapon temp = equipped_weapon;
    equipped_weapon = weap;
    weap = temp;
}

void Player::equipArmor(Item_Armor& arm)
{
    Item_Armor temp = equipped_armor;
    equipped_armor = arm;
    arm = temp;
}

/*
void Player::outputInventory()
{
    cout << inv;
}
*/

ostream& operator<<(ostream& out, const Player& player)
{
    out << "Player Stats\n\tHealth:\tAttack:\tDefense:\t";
    out << "\t" << player.currentHP << "/" << player.MaxHP << "\t" << player.attack << "\t" << player.defense << "\n";
    out << "Player Equipment\n";
    out << player.equipped_weapon << player.equipped_armor;
    return out;
}
