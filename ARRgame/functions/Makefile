WAY := functions
CFILES := $(wildcard *.c)
COMPILER := gcc	
FLAGS := -Werror -Wall -std=c99

ifeq (lib,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif

lib: $(patsubst %.c,%.o,$(CFILES))
	$(COMPILER) -shared $(FLAGS) -o lib$(RUN_ARGS).so $^
	rm *.d *.o

%.o: %.c
	 $(COMPILER) $(FLAGS) -c -fpic -MD $<

include $(wildcard *.d)

clean:
	rm *.d *.o *.exe *.out
