CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -no-pie -m32

.DEFAULT_GOAL: all

.PHONY: all clean

all: main

main: main.o div.o mul.o
	$(CC) $(LDFLAGS) -o $@ $^

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

div.o: div.c
	gcc $(CFLAGS) -c div.c -o div.o

mul.o: mul.c
	gcc $(CFLAGS) -c mul.c -o mul.o

clean:
	-rm -f main main.o mul.o div.o
	-rm -f *~
