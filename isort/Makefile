CC=gcc
CFLAGS=-I.
DEPS = isort.h utils.h
OBJ = isort.o utils.o
VPATH =../utils


%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

isort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
