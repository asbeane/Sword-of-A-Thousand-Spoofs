#include<iostream>
#include<cstdlib>
#include<ctime>
#include"combat.h"
#include"player.h"
#include"room.h"
#include"dungeon.h"
#include "windows.h"

using namespace std;

bool display_choices(Player& playerA, Dungeon& dunA);
void display_inventory_choices(Player& playerA);
bool display_movement_choices(Player& playerA, Dungeon& dunA);

//Max_CLEAR is used for buffer, if more characters  are inputed above max
//it will crash during certain inputs. You could #include limits to get max buffer.
const int MAX_CLEAR = 256;

int main()
{
    srand(static_cast<unsigned int>(time(0)));  // seed random number generator based on current time
    bool game_running = true;
    Player mainProtagonist(25, 4, 2);
    Dungeon theDungeon;
    //Room* currentRoom;

//    for(int i = 0; i < 5; i++)
//    {
//        mainProtagonist.addToInventory(pickRandItem());
//    }

    system("cls");
    while(game_running == true)
    {
        game_running = display_choices(mainProtagonist, theDungeon);

    }
    return 0;
}
/** Display Player Choices
 *
 * Option 1: Look at inventory and have option to make changes also displays status of character
 *              * Calls void display_inventory_choices(Player& playerA);
 * Option 2: Look at Dungeon Map and decided if you want to move or not
 *              * Calls void display_movement_choices(Player& playerA);
 * Option 3: Asks if you want to quit
 *              * Confirms if you really want to quit.
 * Note: System screen gets cleared with every choice:
 *              * bool wrong_input = Produces a wrong input message select again.
 */

bool display_choices(Player& playerA, Dungeon& dunA)
{
    int  player_choice;
    bool wrong_input = false;
    cout << "What would you like to do next:\n\n";
    cout << "1. Look at your Inventory and Status.\n";
    cout << "2. Look at Dungeon Map and move.\n";
    cout << "3. Exit game this sucks.\n";
    cin  >> player_choice;

    if(!cin)
    {
        wrong_input = true;
        cin.clear(); // Clear keyboard buffer
        cin.ignore(MAX_CLEAR, '\n');
    }
    else{
    switch(player_choice)
    {
        case 1://go to inventory
            display_inventory_choices(playerA);
            break;
        case 2://go to dungeon map and move
            bool cont; //continue
            cont = display_movement_choices(playerA, dunA);
            return cont;
            //break;
        case 3://Quiting Game are you sure?
            system("cls");
            cout << "Are you sure you want to quit the best Game in the World???\n";
            cout << "1. Yes I am sure.\n";
            cout << "2. No you're right this game is awesome!\n";
            cin  >> player_choice;
            if(!cin)
                wrong_input = true;
            else{
            switch(player_choice)
            {
                case 1://Okay you can exit..
                    return false;
                case 2://Game continues
                    break;
                default://Wrong input;
                    wrong_input = true;
            }}//Second Else and Switch bracket
            break;
        default:
            wrong_input = true;
    }}//Else and Switch Bracket

    system("cls");//in windows include to clear the screen it clears the screen every loop

    if(wrong_input == true)
        cout << "*~Did not select a valid number~* \n";

    return true;//game is still running
}
/** Displays Players inventory
 *
 *  It first displays player_Status then displays vector of item objects.
 *  Asks user to choose a number to see which item to swap or potion to use in the list.
 *
 *  note: user_input can be string or int type.
 *  It first reads it as a string and then gets converted to a int.
 *  Why because typing a letter could indicate exiting like 'y' for yes
 *  But if the initial input was a 2, it will convert to a int 2 and pick the
 *  second position in the list.
 */
void display_inventory_choices(Player& playerA)
{

    string user_input;
    int  player_choice;
    bool exit = false;
    bool wrong_input = false;
    system("cls");
    cin.ignore();

    do{//while(exit != true);
    wrong_input = false; //reseting bool

    cout << playerA;
    playerA.outputInventory();

    cout << "Type a number that is associated Weapon or Armor to equip.\n";
    cout << "You can only equip one Weapon or Armor at a time.\n";
    cout << "If potion selected it will be used.\n";
    cout << "To exit type 'Y'. Your Choice:";
    getline( cin, user_input );//Safe and works for any input.
    cout << endl;

    if(user_input == "y" || user_input == "Y")
            exit = true;
    player_choice = atoi(user_input.c_str());//If number was entered into string it will convert the string to an int
    if(player_choice > 0)
    {
        playerA.useItem(player_choice);
        system("PAUSE");
    }
    else
        wrong_input = true;

    system("cls");
    if(wrong_input == true)
    {
        cout << "*~Did not select a valid number~* \n";
    }

    }while(exit != true);
}
/** Displays Map and movement
 *
 *  We have not coded it fully yet so this menu might need to change.
 *  Asks user to move to a position, if true, it will display the map one
 *  more time with changes and asks to hit any key to continue before clearing.
 *
 */

bool display_movement_choices(Player& playerA, Dungeon& dunA)
{
    string user_input;
    bool exit = false;
    bool wrong_input = false;
    system("cls");
    cin.ignore();

    do{//while(exit != true);
    wrong_input = false;//reseting bool
    cout << dunA << endl; //***Display Player Map

    cout << "To move please type correct Letter.______ \n";
    cout << "Move Up   = 'W'  Move Left  = 'A'  |  W  |\n";
    cout << "Move Down = 'S'  Move Right = 'D'  |A S D|\n";
    cout << "To exit type 'Y'. Your Choice: ";
    getline( cin, user_input );
    cout << endl;

    if(user_input == "y" || user_input == "Y")
    {
        exit = true;
    }
    else if(user_input == "W" || user_input == "w" || user_input == "A" || user_input == "a" ||
            user_input == "S" || user_input == "s" || user_input == "D" || user_input == "d")
    {
        system("cls");
        //**** playerA(user_input);//Making movement
        //**********************The below code will make so they see there move and pause then exit out
        //***Display Player Map //playerA;
        Room* currentRoom = dunA.getCurrentRoom();
        int roomNumber = 0;
        if(user_input == "W" || user_input == "w")
        {
            roomNumber = currentRoom->get_north();
            currentRoom = dunA.move(roomNumber);
        }
        if(user_input == "S" || user_input == "s")
        {
            roomNumber = currentRoom->get_south();
            currentRoom = dunA.move(roomNumber);
        }
        if(user_input == "D" || user_input == "d")
        {
            roomNumber = currentRoom->get_east();
            currentRoom = dunA.move(roomNumber);
        }
        if(user_input == "A" || user_input == "a")
        {
            roomNumber = currentRoom->get_west();
            currentRoom = dunA.move(roomNumber);
        }
        cout << dunA << endl; //***Display Player Map
        cout << "To move please type correct Letter.______ \n";
        cout << "Move Up   = 'W'  Move Left  = 'A'  |  W  |\n";
        cout << "Move Down = 'S'  Move Right = 'D'  |A S D|\n";
        cout << "To exit type 'Y'. Your Choice: \n";
        system("PAUSE");

        if(roomNumber == 53)
        {
            system("cls");
            cout << "\nAt long last, you gaze upon the room of treasure you were seeking.\n";
            cout << "Amidst the gold and jewels, you find the legendary Sword Of A Thousand Spoofs.\n";
            cout << "With this sword in your hands, nothing will stand in your way ever again!\n";
            cout << "Congratulations!\n\n";

            system("PAUSE");

            int randNum = rand()%2;
            if(randNum == 0)
            {
                system("cls");
                cout << "\nAs you stand basking in your glory, some hooligan stabs you in the back\n";
                cout << "and runs off with the Sword Of A Thousand Spoofs.\n";
                //cout << "Turns out just having it in your hands isn't enough to help you.\n";
                cout << "~GAME OVER~\n";
            }
            return false;
        }
        if(currentRoom->get_enemy())
        {
            bool cont;
            cont = combat(playerA, roomNumber);
            if(cont == false)
            {
                system("cls");
                cout << "~GAME OVER~\n";
                return false;
            }
        }
        if(currentRoom->get_item())
        {
            system("cls");
            cout << "\nYou found an item in this room!\n";
            playerA.addToInventory(pickRandItem());
            system("PAUSE");
        }

        exit = true; // I might need to make a system pause so once
    }
    else
        wrong_input = true;

    system("cls");
    if(wrong_input == true)
        cout << "*~Did not select a valid number~* \n";

    }while(exit != true);
    return true; //game is still running
}
