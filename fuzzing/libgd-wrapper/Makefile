CC=afl-cc
#CC=afl-cc -fsanitize=address
run: main.c
	$(CC) -o wrapper main.c -lm -lgd `pkg-config --cflags`
clean:
	rm wrapper
