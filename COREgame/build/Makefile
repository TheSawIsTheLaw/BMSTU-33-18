COMPILER = gcc

GET_OBJECT = -Wall -Werror -c
GET_APP = -o

HEADERS = ../c_src_headers/*.h

STATIC_NAME = libcore.a
SHARED_NAME = libcore.so

all: libcore.a libcore.so

static: libcore.a
	mv ./libcore.a ../libs
	
shared: libcore.so
	mv ./libcore.so ../libs

libcore.a: $(patsubst %.c, %.o, $(wildcard ../c_src/*.c))  $(HEADERS)
	ar rc $(STATIC_NAME) $(@)  
 
libcore.so: $(patsubst %.c, %.o, $(wildcard ../c_src/*.c)) $(HEADERS)
	$(COMPILER) -shared $(GET_APP) $(SHARED_NAME) $(@)

%.o: %.c
	$(COMPILER) -fPIC $(GET_OBJECT) %.c

clean:
	rm -f *.o

