CC = gcc
CFLAGS = -Wall
DEPS = src/dictionary.h src/kv_pair.h
OBJ = src/dictionary.o src/kv_pair.o test/test_dictionary.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/test_dictionary: $(OBJ)
	mkdir -p bin
	gcc $(CFLAGS) -o $@ $^