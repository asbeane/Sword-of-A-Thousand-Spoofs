#include <cstdlib>
#include <ctime>
#include "combat.h"
#include "player.h"
#include "enemy.h"
#include "inventoryClasses.h"

int main()
{
    srand(time(0));
    int num;
    Player pl1(25, 4, 2);

    for(int i = 0; i < 5; i++)
    {
        pl1.addToInventory(pickRandItem());
    }

    cout << pl1;
    pl1.outputInventory();
    combat(pl1, 2);

    cout << pl1;
    pl1.outputInventory();
    cout << "Input num: ";
    cin >> num;
    pl1.useItem(num);
    cout << pl1;
    pl1.outputInventory();
    cout << "Input num: ";
    cin >> num;
    pl1.useItem(num);
    cout << pl1;
    pl1.outputInventory();
//    Item_Weapon* weap = pickRandWeapon(false); //remember that pickRandWeapon returns a pointer
//    Item_Armor* arm = pickRandArmor(false);
//    pl1.equipWeapon(weap);
//    pl1.equipArmor(arm);

    combat(pl1, 8);

    cout << pl1;
    pl1.outputInventory();
    cout << "Input num: ";
    cin >> num;
    pl1.useItem(num);
    cout << pl1;
    pl1.outputInventory();
    cout << "Input num: ";
    cin >> num;
    pl1.useItem(num);
    cout << pl1;
    pl1.outputInventory();

    combat(pl1, 15);
    cout << pl1;

	return 0;
}
