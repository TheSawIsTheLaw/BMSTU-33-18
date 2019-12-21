CC = gcc
CFLAGS = -Wall -pedantic

all: static dynamic

static: libyes.a test_static
dynamic: libyes.so test_dynamic

yes.o:
	$(CC) $(CFLAGS) -fpic -c yes.c
libyes.so: yes.o
	$(CC) $(CFLAGS) -shared -o -libyes.so yes.o
libyes.a: yes.o
	ar cr $@ yes.o
yes_test.o:
	$(CC) $(CFLAGS) -c yes_test.c
test_dynamic: libyes.so yes_test.o
	$(CC) $(CFLAGS) -o test_dynamic.out yes_test.o
test_static: libyes.a yes_test.o
	$(CC) $(CFLAGS) -o test_static.out yes_test.o
clean:
	rm -f *.o *.out *.so *.a
