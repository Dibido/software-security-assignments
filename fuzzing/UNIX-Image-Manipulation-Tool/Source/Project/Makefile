CC = afl-cc
run: app.c
	$(CC) -o run app.c -lm -lgd `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm run
