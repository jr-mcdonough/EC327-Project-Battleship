GCC=g++ -std=c++11 -g

OBJS=main.o menu.o coordinate.o Instructions.o gamefunction.o 

default: Play

Play: $(OBJS)
	$(GCC) -o Play $(OBJS)

# follow the format for "menu.o" for each new file created (need to use tab on line 2):
# if the new file includes any other files, add each "__.h" file to the line as well

menu.o: menu.cpp menu.h 
	$(GCC) -c menu.cpp -o menu.o
	
gamefunction.o: gamefunction.cpp gamefunction.h
	$(GCC) -c gamefunction.cpp -o gamefunction.o

main.o: main.cpp menu.h coordinate.h Instructions.h
	$(GCC) -c main.cpp -o main.o

coordinate.o: coordinate.cpp coordinate.h
	$(GCC) -c coordinate.cpp -o coordinate.o
	
Instructions.o: Instructions.cpp Instructions.h
	$(GCC) -c Instructions.cpp -o Instructions.o

clean: 
	rm $(OBJS) Play
