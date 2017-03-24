CC=gcc
CFLAGS=-l.

sleepingTA: sleepingTA.o
	$(CC) -o sleepingTA sleepingTA.o -lpthread

 
 
