CFLAGS = -Wall
OBJS   = main.o combat.o enemy.o map_generator.o player.o room.o inventoryClasses.o inventoryFunctions.o

swordTruth : $(OBJS)
	$(CC)-g++ -o swordTruth $(OBJS)
