WAY := functions
WAY_TO_HEADER := headers
INSTALL_WAY := usr
CHANGELOG := (1.0-1) stable; urgency=medium
MD5 := md5deep -r $(INSTALL_WAY) > DEBIAN/md5sums
ARCH := amd64
DEB_CONTROL := DEBIAN/control
DEB_MAINTAINER := Romanov Alexey <romanov.alexey2000@gmail.com>
DEB_DEPENDS := bash, sed (>= 3.02-8)

CFILES := $(wildcard $(WAY)/*.c)
COMPILER := gcc	
FLAGS := -Werror -Wall -std=c99

RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
$(eval $(RUN_ARGS):;@:)

lib: $(patsubst %.c,%.o,$(CFILES))
	$(COMPILER) -shared $(FLAGS) -o lib$(RUN_ARGS).so $^
	rm $(WAY)/*.o

$(WAY)/%.o: $(WAY)/%.c
	 $(COMPILER) $(FLAGS) -c -fpic $< -o $@

deb: 
	mkdir -p $(RUN_ARGS) $(RUN_ARGS)/DEBIAN $(RUN_ARGS)/$(INSTALL_WAY) $(RUN_ARGS)/$(INSTALL_WAY)/include $(RUN_ARGS)/$(INSTALL_WAY)/lib
	echo "$(MD5)" > $(RUN_ARGS)/DEBIAN/md5sums
	echo "$(RUN_ARGS) $(CHANGELOG)" > $(RUN_ARGS)/DEBIAN/changelog
	echo "Package: $(RUN_ARGS)" > $(RUN_ARGS)/DEBIAN/control
	echo "Version: 1.0-1" >> $(RUN_ARGS)/$(DEB_CONTROL)
	echo "Section: libs" >> $(RUN_ARGS)/$(DEB_CONTROL)
	echo "Architecture: $(ARCH)" >> $(RUN_ARGS)/$(DEB_CONTROL)
	echo "Depends: $(DEB_DEPENDS)" >> $(RUN_ARGS)/$(DEB_CONTROL)
	echo "Maintainer: $(DEB_MAINTAINER)" >> $(RUN_ARGS)/$(DEB_CONTROL)
	echo "Description: $(RUN_ARGS) libary" >> $(RUN_ARGS)/$(DEB_CONTROL)
	cp lib$(RUN_ARGS).so $(RUN_ARGS)/$(INSTALL_WAY)/lib
	cp $(WAY_TO_HEADER)/$(RUN_ARGS).h $(RUN_ARGS)/$(INSTALL_WAY)/include
	fakeroot dpkg-deb --build $(RUN_ARGS)
	mv $(RUN_ARGS).deb $(RUN_ARGS)_1.0-1_$(ARCH).deb
	rm -R $(RUN_ARGS)

rpm:
	echo 'todo'

pacman:
	echo 'todo'
	
clean:
	rm *.d *.o *.exe *.out

