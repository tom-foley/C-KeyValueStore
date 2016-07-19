CC = gcc
CFLAGS = -Wall
DEPS = src/kv_store.h src/kv_pair.h
OBJ = src/kv_store.o src/kv_pair.o test/test_kv_store.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

bin/test_kv_store: $(OBJ)
	mkdir -p bin
	gcc $(CFLAGS) -o $@ $^