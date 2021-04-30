CC = clang
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o unit_test.o test_def.o generic_vector.o tree.o

all: hangman unit_test
hangman: main.o my_string.o generic_vector.o tree.o
	$(CC) $(CFLAGS) -o hangman main.o my_string.o generic_vector.o tree.o
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic_vector.h generic_vector.c
	$(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
tree.o: Tree.h Tree.c
	$(CC) $(CFLAGS) -c Tree.c -o tree.o
unit_test: my_string.o unit_test.o test_def.o
	$(CC) -o unit_test unit_test.o test_def.o my_string.o
unit_test.o: unit_test02.c my_string.h unit_test02.h
	$(CC) $(CFLAGS) -c unit_test02.c -o unit_test.o
test_def.o: test_def02.c unit_test02.h my_string.h
	$(CC) $(CFLAGS) -c test_def02.c -o test_def.o
clean:
	rm hangman $(OBJECTS)
	rm unit_test
