COMPILER = gcc

GET_OBJECT = -Wall -Werror -c
GET_APP = -o

LINK_HEADERS = ../c_src_headers/*_headers/*_link.h
UPLOAD_HEADERS = ../c_src_headers/*_headers/*_upload.h

STATIC_NAME = libcore.a
SHARED_NAME = libcore.so
STATIC_UPLOAD_NAME = libcore_upload.a

all: static shared static_upload

static: libcore.a
	mv ./libcore.a ../libs
	
shared: libcore.so
	mv ./libcore.so ../libs

static_upload: libcore.so libcore_upload.a
	mv ./libcore_upload.a ../libs

libcore.a: ../c_src/*_src/*_link.c $(LINK_HEADERS)
	$(COMPILER) $(GET_OBJECT) ../c_src/*_src/*_link.c
	ar rc $(STATIC_NAME) ./*_link.o
 
libcore.so: ../c_src/*_src/*_link.c $(LINK_HEADERS)
	$(COMPILER) $(GET_OBJECT) -fPIC ../c_src/*_src/*_link.c
	$(COMPILER) -shared $(GET_APP) $(SHARED_NAME) *_link.o

libcore_upload.a: ../c_src/*_src/*_upload.c $(UPLOAD_HEADERS)
	$(COMPILER) $(GET_OBJECT) ../c_src/*_src/*_upload.c
	ar rc $(STATIC_UPLOAD_NAME) ./*_upload.o

%.o: %.c
	$(COMPILER) $(GET_OBJECT) -fPIC $(<)

clean:
	rm -f *.o

