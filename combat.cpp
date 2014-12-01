#include <string>
#include <iostream>
#include <cstdlib>
#include "player.h"
#include "enemy.h"
#include "combat.h"
#include "inventoryClasses.h"


using namespace std;


void displayOptions(struct Cooldowns &cds)
{
    cout << "Choose your action! (enter the number of your choice)\n";
    cout << "(1) Weak Attack \n\t-- cause damage enemy health, mitigated by enemy's armor value.\n";
    if(!cds.heavy)
    {
        cout << "(2) Strong Attack \n\t-- cause damage to enemy health as well as damage enemy's armor\n";
    }
    if(!cds.dodge)
    {
        cout << "(3) Dodge \n\t-- if enemy used Strong Attack, avoid damage and counterattack with a weak strike.\n";
    }
    if(!cds.block)
    {
        cout << "(4) Block \n\t-- if enemy used Weak Attack, block damage and regain some health.\n"
    }
}

int getPlayerOption(struct Cooldowns &cds)
{
    int option;
}

