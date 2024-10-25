CC = gcc
CFLAGS := -std=c99 -Wall -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter

all: executable

listes_chainees.o: listes_chainees.c listes_chainees.h
	$(CC) $(CFLAGS) -c listes_chainees.c

main.o: main.c listes_chainees.h
	$(CC) $(CFLAGS) -c main.c

executable: listes_chainees.o main.o
	$(CC) $(CFLAGS) -o executable listes_chainees.o main.o

valgrind: executable
	valgrind --leak-check=full ./executable

run: executable
	./executable

clean:
	rm -f *.o executable
