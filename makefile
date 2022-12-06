CC=g++ -std=c++11 -g

OBJS=main.o 

default: Battleship2022

PA3: $(OBJS)
	$(CC) -o Battleship2022 $(OBJS) 

test.o: test.cpp
	$(CC) -c test.cpp -o test.o 

clean: 
	rm $(OBJS) Battleship2022 *.exe