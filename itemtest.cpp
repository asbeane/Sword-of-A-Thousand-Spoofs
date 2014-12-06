#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inventoryClasses.h"
#include "player.h"

int main()
{
    srand(time(0));
    Player p1(25, 4, 2);
    cout << p1;
    for(int i = 0; i < 5; i++)
    {
        p1.addToInventory(pickRandItem());
    }
    p1.outputInventory();
    p1.useItem(1);
    cout << p1;
    p1.outputInventory();
}
