#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"combat.h"
#include"enemy.h"
#include"inventoryClasses.h"
#include"map_generator.h"
#include"player.h"
#include"room.h"

using namespace std;

int main()
{
	 vector<Room> dungeon;
	 dungeon = map_generator();
	 
	 return 0;
}
