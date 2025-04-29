make all:
	gcc -o lr -g src/main.c src/data_t.c src/csvparser.c src/calculations.c
make clean:
	rm lr
