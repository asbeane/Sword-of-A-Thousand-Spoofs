#ifndef ROOM_H
#define ROOM_H

/*Class Declaration of Room Class*/

#include<iostream>

using namespace std;

class Room
{
	friend class Dungeon;
   protected:
      bool enemy;
      bool item;
      bool visited;
      int north;
      int south;
      int east;
      int west;
		int x;
		int y;
      
   
   public:
      /***********************************************************************
      *Default Constructor                                                   *
      *                                                                      *
      *Create a Room object and decide if an enemy and/or item is present in *
      *the room. Each with an uncorrelated 1/3 chance of appearing.          *  
       ***********************************************************************/
      Room();


      /***********************************************************************
      *Constructor with parameters                                           *        
      *Create a Room object and decide if an enemy and/or item is present in *
      *the room. Each with an uncorrelated 1/3 chance of appearing.          *
      *                                                                      *
      *@param nrth,sth,est,wst                                               *
      *    nrth sets member variable north to an int value.                  *
      *    sth sets member variable south to an int value.                   *
      *    est sets member variable east to an int value.                    *
      *    wst sets member variable west to an int value.                    *
      *                                                                      *
       **********************************************************************/
      Room(int nrth, int sth, int est, int wst, int to_x, int to_y);


      /***********************************************************************
      *Sets boolean member variable vistited to true. Default set value is to*
      *false                                                                 *
      ************************************************************************/
      bool set_visited();

      /***********************************************************************
      *Returns the value of integer member variable north                    *
      *                                                                      *
      ************************************************************************/
      int get_north();

      /***********************************************************************
      *Returns the value of integer member variable south                    *
      *                                                                      *
      ************************************************************************/
      int get_south();

      /***********************************************************************
      *Returns the value of integer member variable east                     *
      *                                                                      *
      ************************************************************************/
      int get_east();

      /***********************************************************************
      *Returns the value of integer member variable west                     *
      *                                                                      *
      ************************************************************************/
      int get_west();

		/***********************************************************************
      *Returns the value of integer member variable x                        *
      *                                                                      *
      ***********************************************************************/
		int get_x();

		/***********************************************************************
      *Returns the value of integer member variable x                        *
      *                                                                      *
      ***********************************************************************/
		int get_y();

		/***********************************************************************
      *Returns the value of boolean member variable enemy                    *
      *                                                                      *
      ***********************************************************************/
		bool get_enemy();

		/***********************************************************************
      *Returns the value of boolean member variable item                     *
      *                                                                      *
      ***********************************************************************/
		bool get_item();


		/***********************************************************************
      *Sets the enemy value given as argument via the formal parameter @value*
      *                                                                      *
      ***********************************************************************/
		bool set_enemy(bool value);

		/***********************************************************************
      *Sets the item value given as argument via the formal parameter @value *
      *                                                                      *
      ************************************************************************/
		bool set_item(bool value);
};

#endif
