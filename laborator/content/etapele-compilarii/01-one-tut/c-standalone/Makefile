CFLAGS = -fno-PIC -m32 -g
LDFLAGS = -nostdinc -nostdlib -no-pie -m32
AS = nasm
ASFLAGS = -f elf32

.DEFAULT_GOAL: all

.PHONY: all clean

all: hello

hello: hello.o start.o puts.o
	#ld -dynamic-linker /lib/ld-linux.so.2 -m elf_i386 -o $@ /usr/lib32/crt1.o /usr/lib32/crti.o $^ -L /usr/lib32/crtn.o
	ld -nostdinc -nostdlib -no-pie -m elf_i386 hello.o puts.o start.o -o hello
	
hello.o: hello.c
	gcc $(CFLAGS) -c hello.c -o hello.o

start.o: start.asm
	$(AS) $(ASFLAGS) -o $@ $<

puts.o: puts.asm
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	-rm -f hello hello.o start.o puts.o
	-rm -f *~
