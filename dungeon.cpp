#include<iostream>
#include<vector>
#include"room.h"
#include"dungeon.h"

using namespace std;

/*Source file for class Dungeon*/

Dungeon::Dungeon()
{
    /*Start Room has no item or enemy*/
    dungeon.push_back(Room(7,-1,2,1,5,2)); //0
    dungeon.at(0).set_enemy(false);
    dungeon.at(0).set_item(false);

    dungeon.push_back(Room(4,-1,-0,-1,5,1)); //1
    dungeon.push_back(Room(-1,-1,3,0,5,3)); //2
    dungeon.push_back(Room(6,-1,-1,2,5,4)); //3
    dungeon.push_back(Room(-1,1,7,5,4,1)); //4
    dungeon.push_back(Room(10,-1,4,-1,4,0)); //5
    dungeon.push_back(Room(8,3,-1,-1,4,4)); //6
    dungeon.push_back(Room(9,0,-1,4,4,2)); //7
    dungeon.push_back(Room(-1,6,-1,11,3,4)); //8
    dungeon.push_back(Room(-1,7,11,-1,3,2)); //9
    dungeon.push_back(Room(12,5,-1,-1,3,0)); //10
    dungeon.push_back(Room(14,-1,8,9,3,3)); //11
    dungeon.push_back(Room(13,10,15,-1,2,0)); //12
    dungeon.push_back(Room(-1,12,17,-1,1,0)); //13
    dungeon.push_back(Room(16,11,-1,-1,2,3)); //14
    dungeon.push_back(Room(17,-1,-1,12,2,1)); //15
    dungeon.push_back(Room(-1,14,-1,18,1,3)); //16
    dungeon.push_back(Room(-1,15,18,13,1,1)); //17
    dungeon.push_back(Room(19,-1,16,17,1,2)); //18

    /*Treasure Room. Has the Treasure! No enemy*/
    dungeon.push_back(Room(-1,18,-1,-1,0,2)); //19
    dungeon.at(19).set_enemy(false);
    dungeon.at(19).set_item(true);

    currentRoom = &(dungeon.at(0)); //initialize currentRoom to point to room 0
    currentRoom->set_visited();

    /*Intitialize all elements of 2D char array to space character*/
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 5; j++)
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
    for(int i = 0; i < 6; i++)
    {
        outs << "   ";
        for(int j = 0; j < 5; j++)
        {
            outs << object.ascii_map[i][j];
            outs << ' ';
        }
        outs << '\n';
    }
    outs << "Map Key:\n@ Current Room\n* Visited Room\nX Unvisited Room\n";

    return outs;
}
