#include<iostream>
#include"room.h"

/*Source File containing definition of class Room*/

using namespace std;

Room::Room()
{
  //Seed randome number generation likely at top of the file. Then utilize the rand for % 3, for 1/3 chance
  //to generate an enemey, and an item.
  //if rand % 3 == 1 give an item, else not
  //if rand % 3 == 1 (re doing random) fight an enemy.

   
}

Room::Room(int nrth, int sth, int est, int wst)
{

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

