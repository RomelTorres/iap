CC=gcc
CFLAGS=-I -ld
DEPS = msort.h
OBJ = msort.o 

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

msort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
