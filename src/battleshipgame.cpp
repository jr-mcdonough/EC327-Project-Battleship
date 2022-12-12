#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib> 
#include "battleshipgame.h"

using namespace std;
bool empty = false;
int sent = 1;

battleshipGame::battleshipGame()//initialize the ships, destroyer has 4 length and carrier 5
:Destroyer(4), Carrier(5) 
{                    
}

battleshipGame::~battleshipGame()//destructor
{
     cout<<"Ship destructed.\n";
}



void battleshipGame::initialize(int lev)//initializes the game
{
     cout << "Intializing level: " << lev << ". Battle field visual coming up..." << endl;
     
     theBoard.setBoard(lev);
     theBoard.initializeBoard();
     theBoard.populate();
     theBoard.setmunitions();//resets the trys and hits or, sets them to their regular numbers. hits=0, ammo=1
     
    while(sent != 0)
     {
     if(theBoard.placeship(Carrier.setx(),Carrier.sety(),Carrier.setHV(),Carrier.getsize(),lev,'C'))
     sent = 0;
     }
     cout << "Carrier presence spotted." << endl;
     sent = 1;

    while(sent !=0)
    {
     if(theBoard.placeship(Submarine.setx(),Submarine.sety(),Submarine.setHV(),Submarine.getsize(),lev,'S'))
     sent=0;
    }
     cout << "Submarine presence spotted." << endl;
     sent=1;
    
    while(sent !=0)
    {
     if(theBoard.placeship(Destroyer.setx(),Destroyer.sety(),Destroyer.setHV(),Destroyer.getsize(),lev,'D'))
     sent=0;
    }
     cout << "Destroyer presence spotted." << endl;
     sent=1;
     theConsole();
     theBoard.printBoard();
     theBoard.setfirst();
     theBoard.setlast();
     //theBoard.showActualBoard();
}


void battleshipGame::theConsole()//return the data 
{
     hits = theBoard.returnhits();
     ammo = theBoard.returnammo();
     theBoard.theConsole();
}

istream& getline(istream& obj, battleshipGame& thisclass)
{
    
    getline(obj, thisclass.theBoard);
    
    thisclass.hity = thisclass.theBoard.returnhity();

    
    
    return obj;
}

istream& operator>>(istream& obj, battleshipGame& thisclass)
{
       obj >> thisclass.theBoard;
       return obj;
}

ostream& operator<<(ostream& objj, const battleshipGame& thisclass)
{
       objj << thisclass.theBoard;
      return objj;
}

void battleshipGame::thelist()
{
     theBoard.printlinkedlist();
}

