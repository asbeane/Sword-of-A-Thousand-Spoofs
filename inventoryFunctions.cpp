
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>          //std::setw(int) it sets width for proper spacing
#include "inventoryClasses.h"

using namespace std;


/***************************************************************************************/
/***************************** Functions for outputting ********************************/
/***************************************************************************************/

void displayHeader()
{
    cout << left << std::setw(19) << "Item Name:" << std::setw(6) << "Qty:" << std::setw(10) << "Type:" << std::setw(6) << "Bonus:\n";
}

void Item::output(ostream& out) const //
{
    out << left << std::setw(19) << m_name << std::setw(6) << m_item_quantity << std::setw(10);
    this->getItemCat();
}

void Item_Weapon::output(ostream& out) const
{
    Item::output(out);
    out << "+" << m_weapon_damage << " ATK\n";
}

void Item_Armor::output(ostream& out) const
{
    Item::output(out);
    out << "+" << m_armor_defense << " DEF\n";
}

void Item_Potion::output(ostream& out) const
{
    Item::output(out);
    if(m_increase_health == 500)
        out << "100%HP";
    else
         out << "+" << m_increase_health << " HP";
    out << endl;
}

ostream& operator <<(ostream& out, const Item& inventory)
{
    inventory.output(out);
    return out;
}

/***************************************************************************************/
/*****************************Class Base Item function calls****************************/
/***************************************************************************************/

int Item::item_timestamp = 0;


Item::Item(string name1, ItemCat itemType)
{
    m_name = name1;         //Name of Object
    enumItemCat = itemType; //Enum category
    m_item_quantity = 1;    //Default quantity 1
    item_timestamp++;       //Increase static by one
}

void Item::getItemCat()const
{
    switch(enumItemCat)
    {
    case 0:
        cout << "Weapon";
        break;
    case 1:
        cout << "Armor ";
        break;
    case 2:
        cout << "Potion";
        break;
    default:
        cout<< "Error in class inventory getItemCat or you have a number greater than 2\n";
    }
};

/***************************************************************************************/
/**********************Class Item_Weapon Function Calls*********************************/
/***************************************************************************************/

ostream& operator<<(ostream& out, const Item_Weapon& inventory)
{
    cout << (Item)inventory << "+" << inventory.getWeaponDamage() << " ATK\n";
    return out;
}

void Item_Weapon::get_pic_axe()
{
        cout << endl;
        cout << "   ,  /\\  . \n"
              "  //`-||-'\\\\ \n"
              " (| -=||=- |) \n"
              "  \\\\,-||-.//  \n"
               "   `  ||  ' \n"
                "      ||    \n"
                "      ||   \n"
                "      ||   \n"
                "      ||   \n"
               "      ||   \n"
               "      ()   \n\n";
}

void Item_Weapon::get_pic_sword()
{
    cout << endl;
    cout << "                /\\                        \n"
            "      _         )( ______________________ \n"
            "     (_)///////(**)______________________>\n"
            "                )(                         \n"
            "                \\/                        \n\n";
}

void Item_Weapon::get_pic_mace()
{
     cout << endl;
     cout << "      \\ | /   \n"
             "     >( + )<  \n"
             "      / | \\   \n"
             "       [ ]    \n"
             "       ] [    \n"
             "       ] [    \n"
             "       ] [    \n"
             "       ]_[    \n"
             "       ]_[    \n"
             "       \\_/    \n\n";
}
/**************************************************************************************/
/**********************Class Item_Armor Function Calls*********************************/
/**************************************************************************************/
ostream& operator<<(ostream& out, const Item_Armor& inventory){
    cout << (Item)inventory << "+" << inventory.getArmorRating() << " DEF\n";
    return out;
}

void Item_Armor::get_pic_shield()
{
    cout << endl;
    cout << "     _______________________      \n"
            "    |<><><>    |  |   <><><>|    \n"
            "    |<>        |  |       <>|    \n"
            "    |          |  |         |    \n"
            "    | /_.-=-.\\ | "" |/.-=-._\\ |   \n"
            "    |  /_    \\(o_o)/    _\\  |    \n"
            "    |   /_  /\\/ ^ \\/\\  _\\   |    \n"
            "    |     \\/ | / \\ | \\/     |    \n"
            "    |______ /((( )))\\ ______|    \n"
            "    |     __\\ \\___/ /__     |    \n"
            "    |-- (((---'   '---))) --|    \n"
            "    :          |  |         :    \n"
            "     \\<>       |  |      <>/      \n"
            "      \\<>      |  |     <>/       \n"
            "       `\\<>    |  |   <>/'        \n"
            "         `\\<>  |  |  <>/'         \n"
            "           `\\<>|  |<>/'           \n"
            "             `-.  .-`             \n"
            "               '--'               \n\n";

}

void Item_Armor::get_pic_helmet()
{
    cout << endl;
    cout << "       _.--.     .--._      \n"
            "    .\"  .\"        \".  \".     \n"
            "    ;  .\"    /\\    \".  ;   \n"
            "    ;  '._,-/  \\-,_.`  ;   \n"
            "    \\  ,`  / /\\ \\  `,  /   \n"
            "     \\/    \\/  \\/    \\/    \n"
            "     ,=_    \\/\\/    _=,    \n"
            "     |  \"_   \\/   _\"  |    \n"
            "     |_   '\"-..-\"'   _|    \n"
            "     | \"-.        .-\" |    \n"
            "     |    \"\\    /\"    |    \n"
            "     |      |  |      |    \n"
            "     |      |  |      |    \n"
            "     '_     |  |     _'    \n"
            "       \"-.  |  |  .-\"      \n"
            "          \"-'--'-\"         \n\n";

}

void Item_Armor::get_pic_chest()
{
    cout << endl;
    cout << "    ,=;~^~^~\\......./~^~^~;=,     \n"
            "    /       ...:::...       \\    \n"
            "   /   /|      :::      |\\   \\   \n"
            "  /   / |   ,,,:::,,,   | \\   \\   \n"
            "        |\\     :::     /|        \n"
            "        | \\ ********* / |        \n"
            "        |\\ \\|*|:::|*|/ /|        \n"
            "        | \\ |*|:::|*| / |        \n"
            "        |  \\|*|:::|*|/  |        \n"
            "        |   *********   |        \n"
            "         \\~~~~~~~~~~~~~/       \n\n";
}
/***************************************************************************************/
/**********************Class Item_Potion Function Calls*********************************/
/***************************************************************************************/

ostream& operator<<(ostream& out, Item_Potion& inventory)
{
    out << (Item)inventory;
    if(inventory.getPotionRating() == 500)
        out << "100%HP";
    else
        out << "+" << inventory.getPotionRating() << " HP";
    out << endl;
    return out;
}

void Item_Potion::get_pic_potion()
{
    cout << endl;
    cout <<  "       _____      \n"
             "      `.___,'     \n"
             "       (___)      \n"
             "       <   >      \n"
             "        ) (       \n"
             "       /   \\      \n"
             "      /     \\     \n"
             "     / _    _\\    \n"
             "    :,' `-.' `:   \n"
             "    |~~~~~~~~~|   \n"
             "    :~~~~~~~~~;   \n"
             "     \\~~~~~~~/    \n"
             "      `.___.'     \n\n";
}

/*******************************************************************************************/
/********************** Other Functions, non class members *********************************/
/*******************************************************************************************/
Item* pickRandItem()
{
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %3 ) + 1; //random number 1 /3

    switch(randomItem)
    {
    case 1:{
        Item_Weapon* random_weapon = pickRandWeapon(true);
        displayHeader();
        cout << *random_weapon;
        return random_weapon;}
    case 2:{
        Item_Armor* random_Armor = pickRandArmor(true);
        displayHeader();
        cout << *random_Armor;
        return random_Armor;}
    case 3:{
        Item_Potion* random_potion = pickRandPotion();
        displayHeader();
        cout << *random_potion;
        return random_potion;}
    default:{//This default case should never happen but if it does... it will make a potion
        Item_Potion* random_potion = pickRandPotion();
        displayHeader();
        cout << *random_potion;
        return random_potion;}
    }
}

Item_Weapon* pickRandWeapon(bool showPics)
{
    //rand() function generates a random number between 0 and at least 32767
    //If you want to know RAND_MAX in cout
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %6 ) + 1; //random number 1-6
    int randomNumber2 = rand();
    int randomItem2 =(randomNumber2 %6 ) + 1;

    switch(randomItem+randomItem2)//This is like rolling two six sided die.
    {
    case 2:{
        Item_Weapon* axe2 = new Item_Weapon("Axe of Devastation", 10);
        if(showPics)
            axe2->get_pic_axe();
        return axe2;}
    case 3:{
        Item_Weapon* sword3 = new Item_Weapon("Sword of Glory", 8);
        if(showPics)
            sword3->get_pic_sword();
        return sword3;}
    case 6:{
        Item_Weapon* sword2 = new Item_Weapon("Sword of Silver", 6);
        if(showPics)
            sword2->get_pic_sword();
        return sword2;}
    case 7:{
        Item_Weapon* sword1 = new Item_Weapon("Sword of Steel", 4);
        if(showPics)
            sword1->get_pic_sword();
        return sword1;}
    case 8:{
        Item_Weapon* mace1 = new Item_Weapon("Mace of Light", 6);
        if(showPics)
            mace1->get_pic_mace();
        return mace1;}
    case 11:{
        Item_Weapon* mace2 = new Item_Weapon("Mace of Windu", 8);
        if(showPics)
            mace2->get_pic_mace();
        return mace2;}
    case 12:{
        Item_Weapon* mace3 = new Item_Weapon("DMMB Mace", 10);// Dont mace me bro
        if(showPics)
            mace3->get_pic_mace();
        return mace3;}
    default:{
        Item_Weapon* axe1 = new Item_Weapon("Axe of Okayness", 2);
        if(showPics)
            axe1->get_pic_axe();
        return axe1;}
    }
}

Item_Armor* pickRandArmor(bool showPics)
{
    //rand() function generates a random number between 0 and at least 32767
    //If you want to know RAND_MAX in cout
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %6 ) + 1; //random number 1-6
    int randomNumber2 = rand();
    int randomItem2 =(randomNumber2 %6 ) + 1;

    switch(randomItem + randomItem2)
    {
    case 2:{
        Item_Armor* shield1 = new Item_Armor("Shield of Hylian", 5);
        if(showPics)
            shield1->get_pic_shield();
        return shield1;}
    case 3:{
        Item_Armor* helm1 = new Item_Armor("Helmet of 6 Sense", 4);
        if(showPics)
            helm1->get_pic_helmet();
        return helm1;}
    case 6:{
        Item_Armor* shield2 = new Item_Armor("Shield of Know", 3);
        if(showPics)
            shield2->get_pic_shield();
        return shield2;}
    case 7:{
        Item_Armor* helm2 = new Item_Armor("Helmet of Steel", 2);
        if(showPics)
            helm2->get_pic_helmet();
        return helm2;}
    case 8:{
        Item_Armor* chest3 = new Item_Armor("Chest of Leather", 3);
        if(showPics)
            chest3->get_pic_chest();
        return chest3;}
    case 11:{
        Item_Armor* chest2 = new Item_Armor("Chest Tanooki Suit", 4);
        if(showPics)
            chest2->get_pic_chest();
        return chest2;}
    case 12:{
        Item_Armor* chest1 = new Item_Armor("Chest of Mark IV", 5);
        if(showPics)
            chest1->get_pic_chest();
        return chest1;}
    default:{
        Item_Armor* shield3 = new Item_Armor("Shield of Wood", 2);
        if(showPics)
            shield3->get_pic_shield();
        return shield3;}
    }
}

Item_Potion* pickRandPotion()
{
    //rand() function generates a random number between 0 and at least 32767
    //If you want to know RAND_MAX in cout
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %4 ) + 1; //random number 1 /4

    switch(randomItem)
    {
    case 1:{//Creating Health Potion that is randomly generated value between 5-12
        Item_Potion* health1 = new Item_Potion("Potion of Health");//Random health potion
        health1->get_pic_potion();
        return health1;}
    case 2:{
        Item_Potion* health2 = new Item_Potion("Potion of Elixir", 500, 0);//Random health potion
        health2->get_pic_potion();
        return health2;}
    case 3:{
        Item_Potion* health4 = new Item_Potion("Potion SuperElixir", 500, 5);
        health4->get_pic_potion();
        cout << "A Super Elixir Potion will also increase your max health by 5.\n\n";
        return health4;}
    default:
        Item_Potion* health3 = new Item_Potion("Potion of Health");//Random health potion
        health3->get_pic_potion();
        return health3;
    }
}

/***************************************************************************************/
/*****************************Class Inventory Function Calls****************************/
/***************************************************************************************/

Inventory::~Inventory()
{
    vector<Item*>::iterator itr;
    for(itr = m_inventory.begin(); itr != m_inventory.end(); itr++)
    {
        delete *itr;
    }
}

void Inventory::add(Item* item)
{
    m_inventory.push_back(item);
}

void Inventory::output()
{
    cout << "\n~YOUR INVENTORY~\n";
    cout << "   ";
    displayHeader();
    int i = 1;
    vector<Item*>::iterator itr;
    for(itr = m_inventory.begin(); itr != m_inventory.end(); itr++, i++)
    {
        cout << i << ") " << **itr;
    }
    cout << endl;
}

int Inventory::getSize()
{
    return m_inventory.size();
}

//does not do bounds checking - any function that calls this should ensure the validity of index
Item* Inventory::getItem(int index)
{
    return m_inventory[index];
}

//does not do bounds checking - any function that calls this should ensure the validity of index
void Inventory::removeItem(int index)
{
    vector<Item*>::iterator itr = m_inventory.begin() + index;
    m_inventory.erase(itr);
}

void Inventory::sortByName()
{

}

//void Inventory::sortByType(vector<Item*> &inventory) //Insertion Sort
//{
//    cout << "Size of Vector// Checking to see if I need to -1 on size:"
//    cout << m_inventory.size() << endl;
//    //might have to do size -1
//    //Int i = 1 // It starts off that way because we look at the second item and asee if the previous one is smaller
//    int j, i;
//    Item *temp = new Item;
//
//    for( i = 1 ; i != inventory.size(); i++)
//    {
//        j = i;
//        *temp = inventory[i];
//        while(j>0 && temp<inventory[j-1])
//        {
//            inventory[j] = inventory[j-1];
//            j--;
//        }
//        inventory[j] = temp;
//    }
//    delete temp;
//    int i, j, tmp;
//---
// for (i=1; i<n; i++)
// {
//     j=i;
//     tmp=data[i];
//     while (j>0 && tmp<data[j-1])
//     {
//           data[j]=data[j-1];
//           j--;
//     }
//     data[j]=tmp;
//}

void Inventory::sortByTime()
{

}

//Player visuals
