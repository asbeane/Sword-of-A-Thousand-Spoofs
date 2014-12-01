CFLAGS = -Wall
OBJS   = combat.o enemy.o map_generator.o player.o room.o inventoryClasses.o

swordTruth : $(OBJS)
	$(CC)-gpp -o swordTruth $(OBJS)
