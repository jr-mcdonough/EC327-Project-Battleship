GCC=g++ -std=c++11 -g

OBJS=main.o menu.o Instructions.o board.o battleshipgame.o ship.o

default: Play

Play: $(OBJS)
	$(GCC) -o Play $(OBJS)

# follow the format for "menu.o" for each new file created (need to use tab on line 2):
# if the new file includes any other files, add each "__.h" file to the line as well

menu.o: menu.cpp menu.h 
	$(GCC) -c menu.cpp -o menu.o
	

main.o: main.cpp menu.h Instructions.h Instructions.o battleshipgame.o 
	$(GCC) -c main.cpp -o main.o
	
Instructions.o: Instructions.cpp Instructions.h
	$(GCC) -c Instructions.cpp -o Instructions.o

ship.o: ship.cpp ship.h
	$(GCC) -c ship.cpp -o ship.o


battleshipgame.o: battleshipgame.cpp battleshipgame.h board.h ship.h
	$(GCC) -c battleshipgame.cpp -o battleshipgame.o

board.o: board.cpp board.h
	$(GCC) -c board.cpp -o board.o



clean: 
	rm $(OBJS) Play
