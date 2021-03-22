CC = gcc
CFLAGS = -g -Wall -Werror
EXPO = fastexpo
MILL = mill
OBJECTS = FastExpo.c MillerRabin.c

speed:FastExpo.c
	$(CC) -o $(EXPO) FastExpo.c $(CFLAGS)
mill:MillerRabin.c
	$(CC) -o $(MILL) MillerRabin.c $(CFLAGS)
clean:
	rm mill fastexpo