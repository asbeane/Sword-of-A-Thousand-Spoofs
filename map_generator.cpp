#include<iostream>
#include<vector>
#include"room.h"
#include"map_generator.h"

using namespace std;

/*Create a dungeon map with vector implementation of 20 Rooms.
  With a start and treasure room with special values.
*/

vector<Room> map_generator()
{
	 vector<Room> dungeon;
	 
    /*Start Room has no item or enemy*/
	 dungeon.push_back(Room(7,-1,2,1));
	 dungeon.at(0).set_enemy(false);
	 dungeon.at(0).set_item(false);

	 dungeon.push_back(Room(4,-1,-0,-1)); //1
	 dungeon.push_back(Room(-1,-1,3,0)); //2
	 dungeon.push_back(Room(6,-1,-1,2)); //3
	 dungeon.push_back(Room(-1,1,7,5)); //4
    dungeon.push_back(Room(10,-1,4,-1)); //5
	 dungeon.push_back(Room(8,3,-1,-1)); //6
	 dungeon.push_back(Room(9,0,-1,4)); //7
	 dungeon.push_back(Room(-1,6,-1,11)); //8
	 dungeon.push_back(Room(-1,7,11,-1)); //9
	 dungeon.push_back(Room(12,5,-1,-1)); //10
	 dungeon.push_back(Room(14,-1,8,9)); //11
	 dungeon.push_back(Room(13,10,15,-1)); //12
	 dungeon.push_back(Room(-1,12,17,-1)); //13
	 dungeon.push_back(Room(16,11,-1,-1)); //14
	 dungeon.push_back(Room(17,-1,-1,12)); //15
	 dungeon.push_back(Room(-1,14,-1,18)); //16
	 dungeon.push_back(Room(-1,15,18,13)); //17
	 dungeon.push_back(Room(19,-1,16,17)); //18

	 /*Treasure Room. Has the Treasure! No enemy*/
	 dungeon.push_back(Room(-1,18,-1,-1)); //19
	 dungeon.at(19).set_enemy(false);
	 dungeon.at(19).set_item(true);
	 return dungeon;
}
