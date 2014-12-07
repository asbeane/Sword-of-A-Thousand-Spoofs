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
		  /***********************************************************
			*Default Constructor                                      *
         *Creates a dungeon map with vector implementaion of 20    *
         *Room Objects. A Start Room (at index 0), and treasure    *
         *Room (at index 19) are created with special enemy and    *
         *item (true/false) values.                                *
         *                                                         *
 			**********************************************************/
        Dungeon();

		  /***********************************************************
		  *Move changes the current room by the index selection in   *
        *references to the (up to) four choices, given the current *
        *room. Move should also update the current map by placing  *
        *an at '@' for the current room. An '*' for visited rooms  *
        *and a ' ' (space) for unvisited                           *                 
        *@param index                                              *
        *     Index referring to which (by index) is the next room *
        *     room selection.                                      *
        *                                                          *
        *@return                                                   *
        *     Returns a pointer to the current room.               *
 		  ***********************************************************/
        Room* move(int index);

		  /**********************************************************
		  *Overloaded C++ output (<<) operator.                     *
        *Will be designed to display ascii_map                    *
        *                                                         *
        *@param outs                                              *
        *      output object                                      *
        *                                                         *      
        *@param object                                            * 
        *      Dungeon objec to display map for                   *
        *                                                         *
        *Displays to the given output (object) buffer the two-    *
        *dimensional character array member ascii_map[6][5]       *     
        **********************************************************/
		  friend ostream& operator <<(ostream &outs, const Dungeon &object);
};
#endif // DUNGEON_H
