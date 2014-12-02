
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>          //std::setw(int) it sets width for proper spacing
#include "inventoryClasses.h"

using namespace std;
/***************************************************************************************/
/*****************************Class Item function calls*********************************/
/***************************************************************************************/
ostream& operator << (ostream& out, const Item& inventory)
{
    out << "Item Name:" << std::setw(14) << "Qty:" << std::setw(7) << "Type:" << std::setw(9) << "Bonus:\n";
    out << std::setw(18) << inventory.getName() << std::setw(4) << inventory.getItemQuantiy() << std::setw(10);
    inventory.getItemCat();
    return out;
}

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
/***************************************************************************************/
/**********************Class Item_Armor Function Calls*********************************/
/***************************************************************************************/
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
            "         \\\~~~~~~~~~~~~~/       \n\n";
}
/***************************************************************************************/
/**********************Class Item_Potion Function Calls*********************************/
/***************************************************************************************/

ostream& operator<<(ostream& out, Item_Potion& inventory)
{
    cout << (Item)inventory;
    if(inventory.getPotionRating() == 500)
        cout << "   " << "MAX";
    else
         cout << "  +" << inventory.getPotionRating();
    cout << endl;
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

/***************************************************************************************/
/**********************Class Other Function Calls*********************************/
/***************************************************************************************/
Item pickRandItem()
{
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %3 ) + 1; //random number 1 /3

    switch(randomItem)
    {
    case 1:{
        Item_Weapon random_weapon = pickRandWeapon();
        cout << random_weapon;
        return random_weapon;}
    case 2:{
        Item_Armor random_Armor = pickRandArmor();
        cout << random_Armor;
        return random_Armor;}
    case 3:{
        Item_Potion random_potion = pickRandPotion();
        cout << random_potion;
        return random_potion;}
    default:{//This default case should never happen but if it does... it will make a potion
        Item_Potion random_potion = pickRandPotion();
        cout << random_potion;
        return random_potion;}
    }
}

Item_Weapon pickRandWeapon()
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
        Item_Weapon axe2("Axe of Devastation", 10);
        axe2.get_pic_axe();
        return axe2;}
    case 3:{
        Item_Weapon sword3("Sword of Glory    ", 8);
        sword3.get_pic_sword();
        return sword3;}
    case 6:{
        Item_Weapon sword2("Sword of Silver   ", 6);
        sword2.get_pic_sword();
        return sword2;}
    case 7:{
        Item_Weapon sword1("Sword of Steel    ", 4);
        sword1.get_pic_sword();
        return sword1;}
    case 8:{
        Item_Weapon mace1("Mace of Light     ", 6);
        mace1.get_pic_mace();
        return mace1;}
    case 11:{
        Item_Weapon mace2("Mace of Windu     ", 8);
        mace2.get_pic_mace();
        return mace2;}
    case 12:{
        Item_Weapon mace3("DMMB Mace         ", 10);// Dont mace me bro
        mace3.get_pic_mace();
        return mace3;}
    default:{
        Item_Weapon axe1("Axe of Okayness   ", 2);
        axe1.get_pic_axe();
        return axe1;}
    }
}

Item_Armor pickRandArmor()
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
        Item_Armor shield1("Shield of Hylian  ", 5);
        shield1.get_pic_shield();
        return shield1;}
    case 3:{
        Item_Armor helm1("Helmet of 6 Sense ", 4);
        helm1.get_pic_helmet();
        return helm1;}
    case 6:{
        Item_Armor shield2("Shield of Know    ", 3);
        shield2.get_pic_shield();
        return shield2;}
    case 7:{
        Item_Armor helm2("Helmet of Steel   ", 2);
        helm2.get_pic_helmet();
        return helm2;}
    case 8:{
        Item_Armor chest3("Chest of Leather  ", 3);
        chest3.get_pic_chest();
        return chest3;}
    case 11:{
        Item_Armor chest2("Chest Tanooki Suit", 4);
        chest2.get_pic_chest();
        return chest2;}
    case 12:{
        Item_Armor chest1("Chest of Mark IV  ", 5);// Dont mace me bro
        chest1.get_pic_chest();
        return chest1;}
    default:{
        Item_Armor shield3("Shield of Wood    ", 2);
        shield3.get_pic_shield();
        return shield3;}
    }
}

Item_Potion pickRandPotion()
{
    //rand() function generates a random number between 0 and at least 32767
    //If you want to know RAND_MAX in cout
	int randomNumber = rand(); //rand()generate random number but in sequence, srand() with time(0), helps seed it in a random position
    int randomItem = (randomNumber %4 ) + 1; //random number 1 /4

    switch(randomItem)
    {
    case 1:{//Creating Health Potion that is randomly generated value between 5-12
        Item_Potion health1("Potion of Health  ");//Random health potion
        health1.get_pic_potion();
        return health1;}
    case 2:{
        Item_Potion health2("Potion of Elixir  ", 500);//Random health potion
        health2.get_pic_potion();
        return health2;}
    case 3:{
        Item_Potion health4("Potion...SupElixir", 500);
        health4.get_pic_potion();
        cout << "A Super Elixir Potion will permanently increase your\nhealth by 5 and restore it to full.\n\n";
        return health4;}
    default:
        Item_Potion health3("Potion of Health  ");//Random health potion
        health3.get_pic_potion();
        return health3;
    }
}

void displayAlphSort()
{

}

void displayTimeAdded()
{

}

void displayQuantity()
{

}
