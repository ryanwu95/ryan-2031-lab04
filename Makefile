CC=gcc
CFLAGS=-lWarn -pedantic

# tester: tester.o libmyifttt.a
# 	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

alarm: alarm.o libmyifttt.a
	$(CC) alarm.o -L. -lmyifttt -lcurl -lwiringPi -o alarm

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

alarm.o:	alarm.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm alarm *.o
