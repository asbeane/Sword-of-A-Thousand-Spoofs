CFLAGS = -Wall
OBJS   = main.o combat.o enemy.o dungeon.o player.o room.o inventoryFunctions.o

swordTruth : $(OBJS)
	$(CC)-g++ -o swordTruth $(OBJS)
