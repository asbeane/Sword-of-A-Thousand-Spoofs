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
    Inventory inv;
    Item_Weapon equipped_weapon;
    Item_Armor equipped_armor;
public:
    /**
     * Player constructor
     * Only need to provide the starting Max HP, base attack, and base defense values.
     * Everything else is handled internally. The player starts with default equipped
     * weapons and armor that provide no bonuses.
     **/
    Player(int hp, int attk, int def);

    /**
     * getMaxHP
     * Accessor for MaxHP
     **/
    int getMaxHP();

    /**
     * setMaxHP
     * Sets MaxHP to the value provided.
     * If a negative value is given, MaxHP is set to zero.
     **/
    void setMaxHP(int value);

    /**
     * getCurrentHP
     * Accessor for currentHP
     **/
    int getCurrentHP();

    /**
     * setCurrentHP
     * Sets currentHP to the value provided.
     * Internally ensures that currentHP stays between 0 and MaxHP, inclusive.
     **/
    void setCurrentHP(int value);

    /**
     * getAttack
     * Returns the total attack strength of the player
     * (base attack stat + bonus from equipped weapon).
     **/
    int getAttack();

    /**
     * getDefense
     * Returns the total defense rating of the player
     * (base defense stat + bonus from equipped armor).
     **/
    int getDefense();

    /**
     * equipWeapon
     * Swaps the weapon pointed to weap with the weapon that
     * the player already has equipped.
     **/
    void equipWeapon(Item_Weapon* weap);

    /**
     * equipArmor
     * Swaps the armor pointed to by arm with the armor that
     * the player already has equipped.
     **/
    void equipArmor(Item_Armor* arm);

    /**
     * addToInventory
     * Pushes the argument item into the player's Inventory.
     * Precondition: item is a pointer to an Item object that has been
     * dynamically allocated.
     **/
    void addToInventory(Item* item);

    /**
     * outputInventory
     * Displays the player's Inventory in numbered list format on the screen.
     **/
    void outputInventory();

    /**
     * useItem
     * Use an item from the player's Inventory by providing the number of the item.
     * The numbers of the items can be seen by calling outputInventory().
     * Items are used in a manner based on their type:
     *      Weapon: Equips the weapon to the player
     *      Armor:  Equips the armor to the player
     *      Potion: Consume the potion and gain its effects, destroying it
     **/
    void useItem(int choice);

    /**
     * overloaded output operator for Player
     * Outputs information about the player's stats and equipment.
     **/
    friend ostream& operator<<(ostream& out, const Player& player);
};
#endif // PLAYER_H
