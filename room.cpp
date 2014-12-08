#include<iostream>
#include<cstdlib>
#include<ctime>
#include"room.h"

/*Source File containing definition of class Room*/

using namespace std;

Room::Room()
{
	 int enemy_generator;
	 int item_generator;
	 visited = false;
	 north = -1;
	 south = -1;
	 east = -1;
	 west = -1;
	 enemy_generator = rand() % 2;
	 if(enemy_generator == 1)
	 {
		  enemy = true;
	 }
	 else
	 {
		  enemy = false;
	 }

    item_generator = rand() % 3;
	 if(item_generator != 0)
	 {
		  item = true;
	 }
	 else
	 {
		  item = false;
	 }



}

Room::Room(int nrth, int sth, int est, int wst, int to_x, int to_y)
{
	 int enemy_generator;
	 int item_generator;
	 visited = false;
	 north = nrth;
	 south = sth;
	 east = est;
	 west = wst;
	 x = to_x;
	 y = to_y;
	 enemy_generator = rand() %2;
	 if(enemy_generator == 1)
	 {
		  enemy = true;
	 }
	 else
	 {
		  enemy = false;
	 }

    item_generator = rand() %3;
	 if(item_generator == 0 || item_generator ==1)
	 {
		  item = true;
	 }
	 else
	 {
		  item = false;
	 }
}

bool Room::set_visited()
{
   visited = true;
   return true;
}

int Room::get_north()
{
   return north;
}

int Room::get_south()
{
   return south;
}

int Room::get_east()
{
  return east;
}

int Room::get_west()
{
   return west;
}

int Room::get_x()
{
	 return x;
}

int Room::get_y()
{
	 return y;
}

bool Room::get_enemy()
{
	 return enemy;
}

bool Room::get_item()
{
    return item;
}

void Room::set_enemy(bool value)
{
	 enemy = value;
}

void Room::set_item(bool value)
{
	 item = value;
}
