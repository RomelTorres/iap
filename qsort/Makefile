CC=gcc
CFLAGS=-I.
DEPS = qusort.h qusort.h
OBJ = qusort.o utils.o
VPATH =../utils


%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

qusort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
