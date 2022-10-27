CC=afl-cc
#CC=afl-cc -fsanitize=address
run: main.c
	$(CC) -o wrapper main.c libgd/Bin/libgd.so -lm `pkg-config --cflags`
clean:
	rm wrapper
