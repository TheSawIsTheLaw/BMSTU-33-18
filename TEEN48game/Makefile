PLAYERS := players
FUNCS := functions
CFILES := $(wildcard functions/*.c players/*.c *.c)
FLAGS := -Wall -Werror -std=c99 -g -O2 -lmatrixgame -larrgame 

app.exe: $(patsubst %.c,%.o,$(CFILES))
	gcc $(MAKEKEY) $^ -o app.exe $(FLAGS)

run: app.exe
	./app.exe

clean: 
	rm *.exe *.out *.o *.d $(FUNCS)/*.o $(FUNCS)/*.d $(PLAYERS)/*.o $(PLAYERS)/*.d

functions/%.o: functions/%.c
	gcc $(FLAGS) -c -o $@ -MD $<

players/%.o: players/%.c
	gcc $(FLAGS) -c -o $@ -MD $<

%.o: %.c 
	gcc $(FLAGS) -c -o $@ -MD $<

include $(wildcard functions/*.d players/*.d)
