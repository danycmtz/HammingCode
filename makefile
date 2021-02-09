CC=gcc
CFLAGS=-I.
DEPS = main.h
OBJ = main.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: run
run:
	 ./main

.PHONY: clean
clean:
	rm -f main main.o
