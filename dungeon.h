#ifndef DUNGEON_H
#define DUNGEON_H

#include<iostream>
#include<vector>
#include"room.h"

using namespace std;

/*New Implementation of Dungeon Generator with Class Implementation*/

class Dungeon
{
    protected:
        vector<Room> dungeon;
        char ascii_map[6][5];
        Room* currentRoom;
    public:
        Dungeon();
        Room* getCurrentRoom();
        void move(int index);
        void displayMap();
};
#endif // DUNGEON_H
