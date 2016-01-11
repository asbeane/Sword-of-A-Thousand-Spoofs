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
	&emsp;&emsp;Print_options; //inventory, move, quit<br>
	&emsp;&emsp;Get_player_option;<br>
	&emsp;&emsp;if(option == 1)<br>
	&emsp;&emsp;{<br>
		&emsp;&emsp;&emsp;&emsp;Display_inventory;<br>
		&emsp;&emsp;&emsp;&emsp;if(User_choose_item)<br>
		&emsp;&emsp;&emsp;&emsp;Use_item;<br>
&emsp;&emsp;}<br>
	&emsp;&emsp;&emsp;&emsp;if(option == 2)<br>
&emsp;&emsp;&emsp;&emsp;{<br>
		&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Dungeon.move(direction);<br>
		&emsp;&emsp;&emsp;&emsp;if(reached treasure) continue = false;<br>
		&emsp;&emsp;&emsp;&emsp;if(room has enemy)<br>
			&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;combat;<br>
			&emsp;&emsp;&emsp;&emsp;if(player_died) continue = false;<br>
	&emsp;&emsp;&emsp;&emsp;	if(room has item)<br>
		&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;	add_to_inventory;<br>
&emsp;&emsp;&emsp;&emsp;	}<br>
	&emsp;&emsp;&emsp;&emsp;If(option == 3)<br>
		&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;Continue = false;<br>
&emsp;&emsp;}<br>

References:<br>
http://www.retrojunkie.com/asciiart/ (for ascii pictures of enemies and items)<br>
http://stackoverflow.com/questions/6027314/inheriting-and-overriding-ostream-operator-in-c (for help on how to get polymorphic behavior for outputting different derived classes)<br>
http://stackoverflow.com/questions/6353149/does-vectorerase-on-a-vector-of-object-pointers-destroy-the-object-itself (answering question about whether vector.erase for a vector of pointers destroys the object that the pointer is pointing to)<br>
http://stackoverflow.com/questions/13986794/clearing-keyboard-buffer-in-c (for tips on properly validating input and clearing buffer)<br>
http://en.cppreference.com/w/ (used for looking up various library functions, etc.)<br>

