CC = gcc
CFLAGS =-I -ld
DEPS = msort.h utils.h
OBJ = msort.o utils.o
VPATH =../utils

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

msort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
