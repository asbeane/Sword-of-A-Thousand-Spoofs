#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include "player.h"
#include "enemy.h"
#include "combat.h"

using namespace std;

void displayOptions(struct Cooldowns &cds);
Action getPlayerOption(struct Cooldowns &cds);
void displayStats(Player &player, Enemy &enemy);
Enemy* createEnemy(int room);
void showPicKnight();
void showPicTroll();
void showPicGhoul();

int combat(Player &player, int room)
{
    Enemy* basicenemy = createEnemy(room);

    struct Cooldowns playercds;
    struct Cooldowns enemycds;
    Action playerAction;
    Action enemyAction;

    //make copy of player defense value so that the change made by heavy attack only applies to this battle
    int playerDef = player.getDefense();
    int enemyDef = basicenemy->getDefense();

    int damage;
    int healAmount = 5;

    //keep going while both player and enemy are alive
    while(player.getCurrentHP() > 0 && basicenemy->getCurrentHP() > 0)
    {
        displayStats(player, *basicenemy);
        playerAction = getPlayerOption(playercds);
        enemyAction = basicenemy->getCombatChoice(enemycds);

        switch(playerAction)
        {
        case WEAKATTACK:
            switch(enemyAction)
            {
            case WEAKATTACK:
                //deal damage to enemy
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                cout << "**You land a weak attack on the enemy, dealing " << damage << " damage**\n";
                //if enemy not defeated, deal damage to player
                if(basicenemy->getCurrentHP() > 0)
                {
                    damage = basicenemy->getAttack() - playerDef;
                    player.setCurrentHP(player.getCurrentHP() - damage);
                    cout << "**The enemy hits you with a weak attack, dealing " << damage << " damage**\n";
                }
                break;
            case HEAVYATTACK:
                //deal damage to enemy
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                cout << "**You land a weak attack on the enemy, dealing " << damage << " damage**\n";
                //if enemy not defeated, deal damage to player and lower player armor value
                if(basicenemy->getCurrentHP() > 0)
                {
                    if(playerDef > 0)
                    {
                        playerDef--;
                    }
                    damage = basicenemy->getAttack() - playerDef;
                    player.setCurrentHP(player.getCurrentHP() - damage);
                    enemycds.heavy = 1;
                    cout << "**The enemy lowers your armor and deals " << damage << " damage with a heavy attack**\n";
                }
                break;
            case DODGE:
                //deal damage to enemy
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                enemycds.dodge = 1;
                cout << "**The enemy tried to dodge but you land a weak attack, dealing " << damage << " damage**\n";
                break;
            case BLOCK:
                //heal enemy
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() + healAmount);
                enemycds.block = 1;
                cout << "**The enemy blocked your weak attack, taking a moment to regain some strength**\n";
                break;
            }
            break;
        case HEAVYATTACK:
            switch(enemyAction)
            {
            case WEAKATTACK:
                //deal damage to enemy and lower enemy armor value
                if(enemyDef > 0)
                {
                    enemyDef--;
                }
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                cout << "**You lower the enemy's armor and deal " << damage << " damage with a heavy attack**\n";
                //if enemy not defeated, deal damage to player
                if(basicenemy->getCurrentHP() > 0)
                {
                    damage = basicenemy->getAttack() - playerDef;
                    player.setCurrentHP(player.getCurrentHP() - damage);
                    cout << "**The enemy hits you with a weak attack, dealing " << damage << " damage**\n";
                }
                break;
            case HEAVYATTACK:
                //deal damage to enemy and lower enemy armor value
                if(enemyDef > 0)
                {
                    enemyDef--;
                }
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                cout << "**You lower the enemy's armor and deal " << damage << " damage with a heavy attack**\n";
                //if enemy not defeated, deal damage to player and lower player armor value
                if(basicenemy->getCurrentHP() > 0)
                {
                    if(playerDef > 0)
                    {
                        playerDef--;
                    }
                    damage = basicenemy->getAttack() - playerDef;
                    player.setCurrentHP(player.getCurrentHP() - damage);
                    enemycds.heavy = 1;
                    cout << "**The enemy lowers your armor and deals " << damage << " damage with a heavy attack**\n";
                }
                break;
            case DODGE:
                //deal damage to player
                damage = basicenemy->getAttack() - playerDef;
                player.setCurrentHP(player.getCurrentHP() - damage);
                enemycds.dodge = 1;
                cout << "**The enemy dodged your heavy attack and countered you, dealing " << damage << " damage**\n";
                break;
            case BLOCK:
                //deal damage to enemy
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                enemycds.block = 1;
                cout << "**The enemy blocked but your heavy attack broke through, dealing " << damage << " damage**\n";
                break;
            }
            playercds.heavy = 1;
            break;
        case DODGE:
            switch(enemyAction)
            {
            case WEAKATTACK:
                //deal damage to player
                damage = basicenemy->getAttack() - playerDef;
                player.setCurrentHP(player.getCurrentHP() - damage);
                cout << "**You tried dodging but the enemy hit you with a weak attack, dealing " << damage << " damage**\n";
                break;
            case HEAVYATTACK:
                //deal damage to enemy
                damage = player.getAttack() - enemyDef;
                basicenemy->setCurrentHP(basicenemy->getCurrentHP() - damage);
                enemycds.heavy = 1;
                cout << "**You dodged the enemy's heavy attack and countered, dealing " << damage << " damage**\n";
                break;
            case DODGE:
                //nothing
                cout << "**You and the enemy both dodged. Nothing happened.**\n";
                enemycds.dodge = 1;
                break;
            case BLOCK:
                //nothing
                cout << "**You dodged while the enemy blocked. Nothing happened.**\n";
                enemycds.block = 1;
                break;
            }
            playercds.dodge = 1;
            break;
        case BLOCK:
            switch(enemyAction)
            {
            case WEAKATTACK:
                //heal player
                player.setCurrentHP(player.getCurrentHP() + healAmount);
                cout << "**You blocked the enemy's weak attack, taking a moment to regain some strength**\n";
                break;
            case HEAVYATTACK:
                //deal damage to player
                damage = basicenemy->getAttack() - playerDef;
                player.setCurrentHP(player.getCurrentHP() - damage);
                enemycds.heavy = 1;
                cout << "You blocked but the enemy's heavy attack broke through, dealing " << damage << " damage**\n";
                break;
            case DODGE:
                //nothing
                cout << "**You blocked while the enemy dodged. Nothing happened.**\n";
                enemycds.dodge = 1;
                break;
            case BLOCK:
                //nothing
                cout << "**You and the enemy both blocked. Nothing happened.**\n";
                enemycds.block = 1;
                break;
            }
            playercds.block = 1;
            break;
        default:
            cout << "Something went wrong somehow and we ended up here.\n";
        }
    }

    delete basicenemy;
    if(player.getCurrentHP() <= 0) //player died
    {
        cout << "\nYOU HAVE DIED\n";
        return 0;
    }
    else //enemy died
    {
        cout << "\nYOU HAVE DEFEATED YOUR FOE\n";
        return 1;
    }

}

void displayOptions(struct Cooldowns &cds)
{
    cout << "Choose your action! (enter the number of your choice)\n";
    cout << "(1) Weak Attack \n\t-- cause damage enemy health, mitigated by enemy's armor value.\n";
    if(!cds.heavy)
    {
        cout << "(2) Heavy Attack \n\t-- cause damage to enemy health as well as damage enemy's armor.\n\t-- 1 turn cooldown\n";
    }
    if(!cds.dodge)
    {
        cout << "(3) Dodge \n\t-- if enemy used Heavy Attack, avoid damage and counterattack.\n\t-- 1 turn cooldown.\n";
    }
    if(!cds.block)
    {
        cout << "(4) Block \n\t-- if enemy used Weak Attack, block damage and regain some health.\n\t-- 1 turn cooldown.\n";
    }
    cout << "Your choice: ";
}

Action getPlayerOption(struct Cooldowns &cds) //Action is the enum type
{
    int option;
    bool correctInput;
    displayOptions(cds);

    do
    {
        correctInput = true; //start at true, will become false if any error checks fail along the way

        cin >> option;

        if(!cin) //make sure that input was actually an integer
        {
            cout << "Enter the NUMBER of your choice: ";
            correctInput = false;
        }
        else
        {
            //ensure choice is between 1 and 4
            if(option < 1 || option > 4)
            {
                cout << "Invalid option. Try again: ";
                correctInput = false;
            }
            //ensure cannot choose heavy attack (option #2) if it is on cooldown
            if(cds.heavy && option == 2)
            {
                cout << "Heavy Attack was used last turn and cannot be used again yet.\nTry again: ";
                correctInput = false;
            }
            if(cds.dodge && option == 3)
            {
                cout << "Dodge was used last turn and cannot be used again yet.\nTry again: ";
                correctInput = false;
            }
            if(cds.block && option == 4)
            {
                cout << "Block was used last turn and cannot be used again yet.\nTry again: ";
                correctInput = false;
            }
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while(correctInput == false);

    //since you are locked into a choice that was not on cooldown at this point, safe to take everything off cooldown
    //(since no two attacks will be on cooldown at the same time)
    cds.heavy = 0;
    cds.dodge = 0;
    cds.block = 0;
    return (Action)option;
}

void displayStats(Player &player, Enemy &enemy)
{
    cout << "\n/////PLAYER\t\t\t\t ENEMY\\\\\\\\\\\n";
    cout << "/////HP: " << setw(2) << player.getCurrentHP() << "\t\t\t\t" << setw(2) << enemy.getCurrentHP() << " :HP\\\\\\\\\\\n";
}

Enemy* createEnemy(int room)
{
    int BestEnemyLowerLimit = 13;
    int StrongerEnemyLowerLimit = 8;
    int EnemyLowerLimit = 1;
    int enemyHP;

    Enemy* enemy;

    if(room >= BestEnemyLowerLimit)
    {
        enemyHP = (rand()%8)+18; //random number between 18 and 25
        enemy = new BestEnemy("Rival Adventurer", enemyHP, 4, 4);
        showPicKnight();
        cout << "Upon entering this room, you encounter a " << enemy->getName() << ".\nHe attacks you, determined to prevent you from finding the treasure first!\n";
        cout << "~Be careful: The " << enemy->getName() << " will certainly know all the same moves as you!\n";
        return enemy;
    }
    if(room >= StrongerEnemyLowerLimit)
    {
        enemyHP = (rand()%7)+12; //random number between 12 and 18
        enemy = new StrongerEnemy("Troll", enemyHP, 4, 2);
        showPicTroll();
        cout << "Upon entering this room, you encounter a " << enemy->getName() << ".\nIt attacks you, enraged from being disturbed.\n";
        cout << "~Be careful: A " << enemy->getName() << " is able to dodge as well as attack.\n";
        return enemy;
    }

    enemyHP = (rand()%5)+8; //random number between 8 and 12
    enemy = new Enemy("Ghoul", enemyHP, 4, 2);
    showPicGhoul();
    cout << "Upon entering this room, you encounter a " << enemy->getName() << ".\nIt becomes startled and attacks you.\n";
    cout << "~Note that a " << enemy->getName() << " is not too bright and only knows how to attack.\n";
    return enemy;
}

void showPicKnight()
{
    cout << endl;
    cout << "       .                   \n"
            "      / \\                  \n"
            "      | |                  \n"
            "      |.|                  \n"
            "      |.|                  \n"
            "      |:|      __          \n"
            "    ,_|:|_,   /  )         \n"
            "      (Oo    / _I_         \n"
            "       +\\ \\  || __|        \n"
            "          \\ \\||___|        \n"
            "            \\ /.:.\\-\\      \n"
            "             |.:. /-----\\  \n"
            "             |___|::oOo::| \n"
            "             /   |:<_T_>:| \n"
            "            |_____\\ ::: /  \n"
            "             | |  \\ \\:/    \n"
            "             | |   | |     \n"
            "             \\ /   | \\___  \n"
            "             / |   \\_____\\ \n"
            "             `-'           \n\n";
}

void showPicTroll()
{
    cout << endl;
    cout << "          |\\  ,,,,,  /|        \n"
            "          | \\/_   _\\/ |        \n"
            "   /\\     (_    \"    _)        \n"
            "   \\ \\      (  ,--, )          \n"
            "   / /    ,,,\\__-__/,,,        \n"
            "   \\ \\   ,,,,\"\"\"\"\"\"\",,,,  ,,,, \n"
            "   /_/   |  |\"\"\"\"\"\"\"(  ) ,(  )    \n"
            "  [!!!]-'  / \"\"\"\"\"\"\" \\  \\ / /  \n"
            "   |!|----' \"\"\"\"\"\"\"\"\" `,___/   \n"
            "            ;;;;;;;;;          \n"
            "            \"\"\"\"\"\"\"\"\"          \n"
            "            \"\"\"\" \"\"\"\"          \n"
            "            \"\"\"   \"\"\"          \n"
            "           _\"\",   ,\"\"_         \n"
            "          (___)   (___)        \n\n";
}

void showPicGhoul()
{
    cout << endl;
    cout << "                 ,____     \n"
            "                  |---.\\   \n"
            "          ___     |    `   \n"
            "         / .-\\  ./=)       \n"
            "        |  |\"|_/\\/|        \n"
            "        ;  |-;| /_|        \n"
            "       / \\_| |/ \\ |        \n"
            "      /      \\/\\( |        \n"
            "      |   /  |` ) |        \n"
            "      /   \\ _/    |        \n"
            "     /--._/  \\    |        \n"
            "     `/|)    |    /        \n"
            "       /     |   |         \n"
            "     .'      |   |         \n"
            "    /         \\  |         \n"
            "   (_.-.__.__./  /         \n\n";
}
