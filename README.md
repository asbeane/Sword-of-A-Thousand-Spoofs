Sword-of-A-Thousand-Spoofs
==========================
Creators:
		  Michael Bertucci
		  Martin Rudzki
		  Andrew Beane

Application Description:

Sword Of A Thousand Spoofs: A text-based dungeon crawler game where the player moves through rooms of a dungeon, fighting enemies and collecting items, in a quest to find the treasure room where the legendary weapon The Sword Of A Thousand Spoofs is said to be hidden.


Pseudocode for main: (simplified just to show basic logic of the program)<br>
While(continue) <br>
{<br>
	Print_options; //inventory, move, quit<br>
	Get_player_option;<br>
	if(option == 1)<br>
	{<br>
		Display_inventory;<br>
		if(User_choose_item)<br>
			Use_item;<br>
	}<br>
	if(option == 2)<br>
{<br>
		Dungeon.move(direction);<br>
		if(reached treasure) continue = false;<br>
		if(room has enemy)<br>
			combat;<br>
			if(player_died) continue = false;<br>
		if(room has item)<br>
			add_to_inventory;<br>
	}<br>
	If(option == 3)<br>
		Continue = false;<br>
}<br>

References:<br>
http://www.retrojunkie.com/asciiart/ (for ascii pictures of enemies and items)<br>
http://stackoverflow.com/questions/6027314/inheriting-and-overriding-ostream-operator-in-c (for help on how to get polymorphic behavior for outputting different derived classes)<br>
http://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself (answering question about whether vector.erase for a vector of pointers destroys the object that the pointer is pointing to)<br>
http://stackoverflow.com/questions/13986794/clearing-keyboard-buffer-in-c (for tips on properly validating input and clearing buffer)<br>
http://en.cppreference.com/w/ (used for looking up various library functions, etc.)<br>

