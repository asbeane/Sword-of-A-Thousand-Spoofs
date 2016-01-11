Sword-of-A-Thousand-Spoofs
==========================
Creators:
		  Michael Bertucci
		  Martin Rudzki
		  Andrew Beane

Application Description:

Sword Of A Thousand Spoofs: A text-based dungeon crawler game where the player moves through rooms of a dungeon, fighting enemies and collecting items, in a quest to find the treasure room where the legendary weapon The Sword Of A Thousand Spoofs is said to be hidden.


Pseudocode for main: (simplified just to show basic logic of the program)
While(continue) <br>
{
	Print_options; //inventory, move, quit
	Get_player_option;
	if(option == 1)
	{
		Display_inventory;
		if(User_choose_item)
			Use_item;
	}
	if(option == 2)
{
		Dungeon.move(direction);
		if(reached treasure) continue = false;
		if(room has enemy)
			combat;
			if(player_died) continue = false;
		if(room has item)
			add_to_inventory;
	}
	If(option == 3)
		Continue = false;
}

References:
http://www.retrojunkie.com/asciiart/ (for ascii pictures of enemies and items)
http://stackoverflow.com/questions/6027314/inheriting-and-overriding-ostream-operator-in-c (for help on how to get polymorphic behavior for outputting different derived classes)
http://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself (answering question about whether vector.erase for a vector of pointers destroys the object that the pointer is pointing to)
http://stackoverflow.com/questions/13986794/clearing-keyboard-buffer-in-c (for tips on properly validating input and clearing buffer)
http://en.cppreference.com/w/ (used for looking up various library functions, etc.)

