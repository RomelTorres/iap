CC=gcc
CFLAGS=-I.
DEPS = hsort.h hsort.h
OBJ = hsort.o utils.o
VPATH =../utils


%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

hsort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
