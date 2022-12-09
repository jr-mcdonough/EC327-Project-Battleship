GCC=g++ -std=c++11 -g

OBJS=main.o menu.o

default: Play

Play: $(OBJS)
	$(GCC) -o Play $(OBJS)

# follow the format for "menu.o" for each new file created (need to use tab on line 2):
# if the new file includes any other files, add each "__.h" file to the line as well

menu.o: menu.cpp menu.h
	$(GCC) -c menu.cpp -o menu.o
	
main.o: main.cpp menu.h
	$(GCC) -c main.cpp -o main.o

clean: 
	rm $(OBJS) Play