#include <iostream>
#include "inventoryClasses.h"
#include "player.h"

using namespace std;

Player::Player(int hp, int attk, int def): inv(), equipped_weapon("Paper Sword", 0), equipped_armor("Torn Clothes", 0)
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

void Player::equipWeapon(Item_Weapon* weap)
{
    //swap *weap with equipped weapon
    Item_Weapon temp = equipped_weapon;
    equipped_weapon = *weap;
    *weap = temp;
}

void Player::equipArmor(Item_Armor* arm)
{
    //swap *arm with equipped armor
    Item_Armor temp = equipped_armor;
    equipped_armor = *arm;
    *arm = temp;
}

void Player::addToInventory(Item* item)
{
    inv.add(item);
}

void Player::outputInventory()
{
    inv.output();
}


void Player::useItem(int choice)
{
    if(choice < 1 || choice > inv.getSize())
    {
        cout << "There is no item with that number.\n";
    }
    else
    {
        Item* item = inv.getItem(choice - 1);
        switch(item->enumItemCat)
        {
        case 0:
            cout << "You have equipped " << item->getName() << " as your weapon.\n";
            equipWeapon((Item_Weapon*)item);
            break;
        case 1:
            cout << "You have equipped " << item->getName() << " as your armor.\n";
            equipArmor((Item_Armor*)item);
            break;
        case 2:
            {
                int health_incr = ((Item_Potion*)item)->getPotionRating();
                if(health_incr == 500) //500 is a value indicating to fully restore player health
                {
                    //increase max HP, possibly by 0 depending on the potion
                    //only potions with the 500 flag would ever change the max HP of the player
                    MaxHP += ((Item_Potion*)item)->getMaxIncr();
                    setCurrentHP(MaxHP);
                }
                else
                {
                    setCurrentHP(currentHP + health_incr);
                }
                cout << "You use the " << item->getName() << " and your health is now " << currentHP << "/" << MaxHP << ".\n";
                inv.removeItem(choice - 1); //remove the potion from the vector once it is used
                delete item; //removing a pointer from a vector does not call destructor, so must manually delete it here
            }
            break;
        default: //should never happen
            cout<< "Error: Invalid item category enum\n";
        }
    }

}


ostream& operator<<(ostream& out, const Player& player)
{
    out << "\n~PLAYER STATS~\nHealth:\tAttack:\tDefense:\n";
    out << player.currentHP << "/" << player.MaxHP << "\t  " << player.attack << "\t  " << player.defense << "\n";
    out << "~PLAYER EQUIPMENT~\n";
    displayHeader();
    out << player.equipped_weapon << player.equipped_armor;
    return out;
}
