#ifndef inventoryClasses_H
#define inventoryClasses_H
#include <iostream>
#include <cstdlib>


using namespace std;


class Item
{
    friend ostream& operator<<(ostream& out, const Item& inventory);
protected:
    string  m_name;             //Name of items
    int     m_modifier;
    int     m_item_quantity;     //Quantity of a particular item
    static int item_timestamp;  //Time stamps of item so we can organize when item was actually received

public:
    enum ItemCat{Weapon, Armor, Potion}enumItemCat;      //Item Category
    Item(string name1, ItemCat itemType);                //Constructor with parameters //Dont know if I really need this
    static int get_timestamp(){return item_timestamp;};  //Get total of objects
    string getName()const {return m_name;};              //Get Name of Object
    int getItemQuantiy() const {return m_item_quantity;};//Get ITem quantity Of object
    void getItemCat()const;                              //Get item Category of object like Weapon, Armor, Potion;
};

class Item_Weapon: public Item
{
    friend ostream& operator<<(ostream& out, const Item_Weapon& inventory)
    {
        cout << (Item)inventory << "  +" << inventory.getWeaponDamage() <<  endl;
        return out;
    }
protected:
    int m_weapon_damage;

public:
    Item_Weapon(string name, int weapon_damage): Item(name, Weapon){ //constructor with parameters, Weapon = Category
        m_weapon_damage = weapon_damage;
    }
    int getWeaponDamage() const {return m_weapon_damage;};
    //Item_Weapon pickRandWeapon();
    void get_pic_axe();
    void get_pic_sword();
    void get_pic_mace();
};
class Item_Armor: public Item
{
friend ostream& operator<<(ostream& out, const Item_Armor inventory){
    cout << (Item)inventory << "  +"<<inventory.getArmorRating() << endl;
    return out;
}
protected:
    int m_armor_defense;

public:
    Item_Armor(string name, int armor_defense): Item(name, Armor){
        m_armor_defense = armor_defense;
    }
    int getArmorRating() const {return m_armor_defense;};
    void get_pic_shield();
    void get_pic_helmet();
    void get_pic_chest();
};

class Item_Potion: public Item
{
    friend ostream& operator<<(ostream& out, Item_Potion& inventory);
protected:
    int m_increase_health;

public:
    Item_Potion(string name, int increase_health): Item(name, Potion){
        m_increase_health = increase_health;
    }
    //Makes a Health Potion that generates a range between 5-12
    Item_Potion(string name): Item(name, Potion){
        int randomNumberHealth = rand();
        int potion_value = (randomNumberHealth % 8) + 5;
        m_increase_health = potion_value;
    }
    int getPotionRating() const {return m_increase_health;};
    void get_pic_potion();
};
Item        pickRandItem();  //Picks Random Weapon, Armor, Potion
Item_Weapon pickRandWeapon(bool showPics);
Item_Armor  pickRandArmor(bool showPics);
Item_Potion pickRandPotion();

#endif
