CC=gcc
CFLAGS=-I.
DEPS = isort.h
OBJ = isort.o 

%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)

isort: $(OBJ)
		gcc -o $@ $^ $(CFLAGS)
clean:
	rm -rf *.o *~
