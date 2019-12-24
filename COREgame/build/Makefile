COMPILER = gcc

GET_OBJECT = -Wall -Werror -c
GET_APP = -o

HEADERS = ../c_src_headers/*_headers/*_link.h

STATIC_NAME = libcore.a
SHARED_NAME = libcore.so

all: static shared

static: libcore.a
	mv ./libcore.a ../libs
	
shared: libcore.so
	mv ./libcore.so ../libs

libcore.a: ../c_src/*_src/*_link.c $(HEADERS)
	$(COMPILER) $(GET_OBJECT) ../c_src/*_src/*_link.c
	ar rc $(STATIC_NAME) ./*.o
 
libcore.so: ../c_src/*_src/*_link.c $(HEADERS)
	$(COMPILER) $(GET_OBJECT) -fPIC ../c_src/*_src/*_link.c
	$(COMPILER) -shared $(GET_APP) $(SHARED_NAME) *.o

%.o: %.c
	$(COMPILER) $(GET_OBJECT) -fPIC $(<)

clean:
	rm -f *.o

