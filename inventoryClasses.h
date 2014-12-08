#ifndef inventoryClasses_H
#define inventoryClasses_H
#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

/** Class Base Item
 *
 *  Item will be a base type for Weapon, Armor, Potion
 *  Constructor will automatically set a enum of what each object is
 */

class Item
{
    friend ostream& operator<<(ostream& out, const Item& inventory);
protected:
    string  m_name;             //Name of items
    int     m_item_quantity;    //Quantity of a particular item
    static int item_timestamp;  //Time stamps of item so we can organize when item was actually received

public:
    enum ItemCat{Weapon, Armor, Potion}enumItemCat;      //Enum Item Category
    Item(string name1, ItemCat itemType);                //Constructor with parameters
    string getName()const {return m_name;}               //Get Name of Object
    virtual ~Item(){}                                    //Destructor
    int getItemQuantiy() const {return m_item_quantity;} //Get ITem quantity Of object
    static int get_timestamp(){return item_timestamp;}   //Get total of objects
    void getItemCat()const;                              //Get item Category of object like Weapon, Armor, Potion;
    virtual void output(ostream& out) const;             //Output
};

/**
 *
 *  Class Derived Item_Weapon
 *
 */

class Item_Weapon: public Item
{
    friend ostream& operator<<(ostream& out, const Item_Weapon& inventory);
protected:
    int m_weapon_damage;

public:
    //constructor with parameters, Weapon = Category already set
    Item_Weapon(string name, int weapon_damage): Item(name, Weapon){m_weapon_damage = weapon_damage;}
    ~Item_Weapon(){} //Destructor
    int getWeaponDamage() const {return m_weapon_damage;};
    void output(ostream& out) const;
    void get_pic_axe();
    void get_pic_sword();
    void get_pic_mace();
};

/**
 *
 *  Class Derived Item_Armor
 *
 */

class Item_Armor: public Item
{
    friend ostream& operator<<(ostream& out, const Item_Armor& inventory);
protected:
    int m_armor_defense;

public:
    void output(ostream& out) const;
    Item_Armor(string name, int armor_defense): Item(name, Armor){
        m_armor_defense = armor_defense;
    }
    ~Item_Armor(){}
    int getArmorRating() const {return m_armor_defense;};
    void get_pic_shield();
    void get_pic_helmet();
    void get_pic_chest();
};
/** Class Derived Item_Potion
 *
 *  Potion has two constructors one of them being
 *  standard and the other creating a potion that randomly generates between 5-12
 */
class Item_Potion: public Item
{
    friend ostream& operator<<(ostream& out, Item_Potion& inventory);
protected:
    int m_increase_health;
    int m_increase_maxhealth;
public:
    void output(ostream& out) const;
    Item_Potion(string name, int increase_health, int max_increase): Item(name, Potion)
    {
        m_increase_health = increase_health;
        m_increase_maxhealth = max_increase;
    }
    //Makes a Health Potion that generates a range between 5-12
    Item_Potion(string name): Item(name, Potion){
        int randomNumberHealth = rand();
        int potion_value = (randomNumberHealth % 8) + 5;
        m_increase_health = potion_value;
        m_increase_maxhealth = 0;
    }
    ~Item_Potion(){}
    int getPotionRating() const {return m_increase_health;}
    int getMaxIncr() const {return m_increase_maxhealth;}
    void get_pic_potion();
};

class Inventory
{
private:
    vector<Item*> m_inventory;
public:
    ~Inventory();
    void add(Item* item); //push_back
    void output(); //output the list of items in the inventory
    int getSize();
    Item* getItem(int index);
    void removeItem(int index);
    void sortByName();
    void sortByType();
    void sortByTime();
};

Item*        pickRandItem();  //Picks Random Weapon, Armor, Potion
Item_Weapon* pickRandWeapon(bool showPics);
Item_Armor*  pickRandArmor(bool showPics);
Item_Potion* pickRandPotion();
void displayHeader();

#endif
