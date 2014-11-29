Sword-of-A-Thousand-Spoofs
==========================

Text based dungeon crawler in C++

The objective of this game is create a map of 20 rooms in which the user (player object) navigates through the rooms
in an attempt to get to a final "Treasure Room" where the prize lays. In each room the player will access inventory,
choose to equip/use an item, and then by random generation will fight an enemy, and there may be an item to gather.

The Items are a class-based system using inheritance from a Parent class "Item" which then contains children classes:
Armor, Weapons, and Potions.

The Dungeon-Map is generated using the STL class vector, using integer member variables to refer to to the indices of
accessible rooms from the current rooms. 

The Enemies and Combat System are still conceptually a work in progress.


