#include<iostream>
#include<vector>
#include"room.h"
#include"dungeon.h"

using namespace std;

/*Source file for class Dungeon*/

Dungeon::Dungeon()
{
/*Start Room has no item or enemy*/
    dungeon.push_back(Room(2, -1, 3, 1, 7, 4)); //0
    dungeon.at(0).set_enemy(false);
    dungeon.at(0).set_item(false);

    dungeon.push_back(Room(5, -1, 0, 4, 7, 3)); //1
    dungeon.push_back(Room(-1, 0, 6, 5, 6, 4)); //2
    dungeon.push_back(Room(6, -1, 7, 0, 7, 5)); //3
    dungeon.push_back(Room(-1, -1, 1, 8, 7, 2)); //4
    dungeon.push_back(Room(9, 1, 2, -1, 6, 3)); //5
    dungeon.push_back(Room(10, 3, -1, 2, 6, 5)); //6
    dungeon.push_back(Room(-1, -1, -1, 3, 7, 6)); //7
    dungeon.push_back(Room(-1, -1, 4, 11, 7, 1)); //8
    dungeon.push_back(Room(13, 5, -1, 12, 5, 3)); //9
    dungeon.push_back(Room(14, 6, 15, -1, 5, 5)); //10
    dungeon.push_back(Room(17, -1, 8, -1, 7, 0)); //11
    dungeon.push_back(Room(-1, -1, 9, 18, 5, 2)); //12
    dungeon.push_back(Room(19, 9, 16, -1, 4, 3)); //13
    dungeon.push_back(Room(20, 10, -1, 16, 4, 5)); //14
    dungeon.push_back(Room(-1, -1, 21, 10, 5, 6)); //15
    dungeon.push_back(Room(-1, -1, 14, 13, 4, 4)); //16
    dungeon.push_back(Room(22, 11, -1, -1, 6, 0)); //17
    dungeon.push_back(Room(23, -1, 12, 22, 5, 1)); //18
    dungeon.push_back(Room(-1, 13, -1, 24, 3, 3)); //19
    dungeon.push_back(Room(-1, 14, -1, -1, 3, 5)); //20
    dungeon.push_back(Room(26, 25, -1, 15, 5, 7)); //21
    dungeon.push_back(Room(27, 17, 18, -1, 5, 0)); //22
    dungeon.push_back(Room(28, 18, -1, 27, 4, 1)); //23
    dungeon.push_back(Room(29, -1, 19, 28, 3, 2)); //24
    dungeon.push_back(Room(21, -1, 30, -1, 6, 7)); //25
    dungeon.push_back(Room(-1, 21, 31, -1, 4, 7)); //26
    dungeon.push_back(Room(-1, 22, 23, -1, 4, 0)); //27
    dungeon.push_back(Room(32, 23, 24, -1, 3, 1)); //28
    dungeon.push_back(Room(-1, 24, -1, 32, 2, 2)); //29
    dungeon.push_back(Room(-1, 33, -1, 25, 6, 8)); //30
    dungeon.push_back(Room(34, -1, -1, 26, 4, 8)); //31
    dungeon.push_back(Room(37, 28, 29, 36, 2, 1)); //32
    dungeon.push_back(Room(30, -1, -1, -1, 7, 8)); //33
    dungeon.push_back(Room(35, 31, -1, -1, 3, 8)); //34
    dungeon.push_back(Room(39, 34, -1, 38, 2, 8)); //35
    dungeon.push_back(Room(-1, -1, 32, -1, 2, 0)); //36
    dungeon.push_back(Room(40, 32, -1, -1, 1, 1)); //37
    dungeon.push_back(Room(42, -1, 35, 43, 2, 7)); //38
    dungeon.push_back(Room(-1, 35, -1, 42, 1, 8)); //39
    dungeon.push_back(Room(-1, 37, 45, 41, 0, 1)); //40
    dungeon.push_back(Room(-1, -1, 40, -1, 0, 0)); //41
    dungeon.push_back(Room(44, 38, 39, 46, 1, 7)); //42
    dungeon.push_back(Room(46, -1, 38, -1, 2, 6)); //43
    dungeon.push_back(Room(-1, 42, -1, -1, 0, 7)); //44
    dungeon.push_back(Room(-1, -1, 47, 40, 0, 2)); //45
    dungeon.push_back(Room(-1, 43, 42, 51, 1, 6)); //46
    dungeon.push_back(Room(-1, 50, 49, 45, 0, 3)); //47
    dungeon.push_back(Room(-1, 51, -1, 49, 0, 5)); //48
    dungeon.push_back(Room(-1, 52, 48, 47, 0, 4)); //49
    dungeon.push_back(Room(47, -1, 52, -1, 1, 3)); //50
    dungeon.push_back(Room(48, -1, 46, 52, 1, 5)); //51
    dungeon.push_back(Room(49, 53, 51, 50, 1, 4)); //52


//    dungeon.push_back(Room(4,-1,-0,-1,5,1)); //1
//    dungeon.push_back(Room(-1,-1,3,0,5,3)); //2
//    dungeon.push_back(Room(6,-1,-1,2,5,4)); //3
//    dungeon.push_back(Room(-1,1,7,5,4,1)); //4
//    dungeon.push_back(Room(10,-1,4,-1,4,0)); //5
//    dungeon.push_back(Room(8,3,-1,-1,4,4)); //6
//    dungeon.push_back(Room(9,0,-1,4,4,2)); //7
//    dungeon.push_back(Room(-1,6,-1,11,3,4)); //8
//    dungeon.push_back(Room(-1,7,11,-1,3,2)); //9
//    dungeon.push_back(Room(12,5,-1,-1,3,0)); //10
//    dungeon.push_back(Room(14,-1,8,9,3,3)); //11
//    dungeon.push_back(Room(13,10,15,-1,2,0)); //12
//    dungeon.push_back(Room(-1,12,17,-1,1,0)); //13
//    dungeon.push_back(Room(16,11,-1,-1,2,3)); //14
//    dungeon.push_back(Room(17,-1,-1,12,2,1)); //15
//    dungeon.push_back(Room(-1,14,-1,18,1,3)); //16
//    dungeon.push_back(Room(-1,15,18,13,1,1)); //17
//    dungeon.push_back(Room(19,-1,16,17,1,2)); //18

    /*Treasure Room. Has the Treasure! No enemy*/
    dungeon.push_back(Room(52, -1, -1, -1, 2, 4)); //53
    dungeon.at(19).set_enemy(false);
    dungeon.at(19).set_item(true);

    currentRoom = &(dungeon.at(0)); //initialize currentRoom to point to room 0
    currentRoom->set_visited();

    /*Intitialize all elements of 2D char array to space character*/
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            ascii_map[i][j] = ' ';
        }
    }

    ascii_map[currentRoom->x][currentRoom->y] = '@'; //set starting room to @ to indicate current location

    //initialize all rooms adjacent to starting room in the map
    Room* adjacent;
    if(currentRoom->north >= 0)
    {
        adjacent = &dungeon.at(currentRoom->north);
        ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->south >= 0)
    {
        adjacent = &dungeon.at(currentRoom->south);
        ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->east >= 0)
    {
        adjacent = &dungeon.at(currentRoom->east);
        ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->west >= 0)
    {
        adjacent = &dungeon.at(currentRoom->west);
        ascii_map[adjacent->x][adjacent->y] = 'X';
    }
}

Room* Dungeon::move(int index)
{
    currentRoom->set_enemy(false);
    currentRoom->set_item(false);
    if(index < 0)
    {
        cout << "There is no adjacent room in that direction.\n";
        return currentRoom;
    }

    //Update ascii map and assign new current room
    ascii_map[currentRoom->x][currentRoom->y] = '*';

    currentRoom = &(dungeon.at(index));

    currentRoom->set_visited();
    ascii_map[currentRoom->x][currentRoom->y] = '@';
    Room* adjacent;
    if(currentRoom->north >= 0)
    {
        adjacent = &dungeon.at(currentRoom->north);
        if(adjacent->visited != true)
            ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->south >= 0)
    {
        adjacent = &dungeon.at(currentRoom->south);
        if(adjacent->visited != true)
            ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->east >= 0)
    {
        adjacent = &dungeon.at(currentRoom->east);
        if(adjacent->visited != true)
            ascii_map[adjacent->x][adjacent->y] = 'X';
    }
    if(currentRoom->west >= 0)
    {
        adjacent = &dungeon.at(currentRoom->west);
        if(adjacent->visited != true)
            ascii_map[adjacent->x][adjacent->y] = 'X';
    }

    return currentRoom;
}

ostream& operator <<(ostream &outs, const Dungeon &object)
{
    for(int i = 0; i < 8; i++)
    {
        outs << "  ";
        for(int j = 0; j < 9; j++)
        {
            outs << object.ascii_map[i][j];
            outs << ' ';
        }
        outs << '\n';
    }
    outs << "Map Key:\n@ Current Room\n* Visited Room\nX Unvisited Room\n";

    return outs;
}
