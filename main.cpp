#include <iostream>
#include <ctime>
#include "coordinate.h"
#include"string"
#include "menu.h"

using namespace std;
//0 is no ship or not visible
//1 is nonvisible ship
//2 is injured ship
//Can add file io that store and read highest scores
const int rows = 10;
const int elements = 10;
 
int maxships = 10;
 
int matrix[rows][elements];

//Function check if two coordinates are the same, if yes return true
bool checkSamePoint(const Coordinate c1, const Coordinate c2){
    if (c1.x==c2.x && c1.y == c2.y){
        return true;
    }else
        return false;
}

//Function check the length between two coordinates
int findLength(const Coordinate c1, const Coordinate c2){
    int length;
    length=c2.y-c1.y;
    return length;
}
//Function check if the two coordinates are either vertically or horizontally straight, if straight return true
bool checkStraight(const Coordinate c1, const Coordinate c2){
    if (c1.x==c2.x || c1.y==c2.y){
        return true;
    }else
        return false;
}

 
void Clear()//This function is used to reset the board for the game

{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
 
void Show()//This function is used to show the board to the player

{
    for(int i=0; i < rows; i++)
    {
        cout<<i<<"| ";
        for(int j=0; j < elements; j++)
        {
            if(matrix[i][j]!=2)
                cout <<0<< " ";
            else
                cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<"   ___________________\n";
    cout<<"   0 1 2 3 4 5 6 7 8 9\n";
}

void ShowFinal()//the actual location of ship
{
    for(int i=0; i < rows; i++)
    {
        cout<<i<<"| ";
        for(int j=0; j < elements; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"   ___________________\n";
    cout<<"   0 1 2 3 4 5 6 7 8 9\n";
}
 // NumberOfShips(): This functions checks the number of ships remaining on the board after a player has chooses a location to attack.

int NumberOfShips()//get the number of ships
{
    int c = 0;
 
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            if(matrix[i][j] == 1)
                c++;
        }
    }
 
    return c;
}
 
void SetCruisers()//3 units length,2 cruisers per game
{
                //generate a random location on the board
        int x = rand() % rows;
        int y = rand() % elements;
             //Check if there is already a ship in that location
        matrix[x][y] = 1;
        matrix[x+1][y] = 1;
        matrix[x+2][y] = 1;
                //generate a random location on the board
        int z = rand() % rows;
        int h = rand() % elements;
             //Check if there is already a ship in that location
        while(z!=x&&z!=x+1&&z!=x+2&&h!=y&&h!=y+1&&h!=y+2)
        {
            z = rand() % rows;
            h = rand() % elements;
        }
        matrix[z][h] = 1;
        matrix[z][h+1] = 1;
        matrix[z][h+2] = 1;
        
    
}

void SetFrigate()//SetShips(): The default board is a matrix filled with zeros as shown in the function Show(), the function SetShip() will choose a random location (x,y) on the board to place a ship there and replaces the value of 0 by 1 at location (x,y). It will loop until it has placed the number of ships according to the int maxships value.
{
        //Generate random ships on board
    int s = 0;
    while(s < maxships-2)
    {
                //generate a random location on the board
        int x = rand() % rows;
        int y = rand() % elements;
             //Check if there is already a ship in that location

        if(matrix[x][y] != 1)
        {
                     //If that location is free, denotes that location with number 1

            s++;
            matrix[x][y] = 1;
        }
        else
        {
            x = rand() % rows;
            y = rand() % elements;
            matrix[x][y] = 1;
            s++;
        }
    }
}

  //Attack(): This functions check if the location that the player chooses has a ship or not. If there is a ship at location, change that location value from 1 to 2 and return true, else if there is no ship return false.

bool Attack(int x,int y)
{
    if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}
 
int main()
{
    Menu();
    srand(time(NULL));
    Clear();
    SetCruisers();
    SetFrigate();
    int pos1,pos2,acount=0;
    char prompt;
    bool samePointCheck;
    bool straightCheck;
    int length;
    
    //Check number of ships
        int shipRemaining=NumberOfShips();
        
    cout<<">>>Welcome to Battleship!<<<\n";
    cout<<"0 means no ship or hidden ship, 2 means injured ship.\n";
    cout<<"Goal is to hit every ship under minimum moves.\n";
    
    /*
     User first input the location of the ships,then the player and computer takes turn guessing one another ship's position
     */
    cout<<"You will have 5 different ship types with different sizes to assign a location, they are the following: "<<endl;
    cout<<"Destroyer - 2 squares"<<endl;
    cout<<"Submarine - 3 squares"<<endl;
    cout<<"Cruiser - 3 squares"<<endl;
    cout<<"Battleship - 4 squares"<<endl;
    cout<<"Carrier - 5 squares"<<endl;
    
    cout<<"Please note that you can only position them vertically or horizontally straight and with correct dimension."<<endl;
    
    
    int coordX,coordY;
    cout<<"Please choose the starting coordinate for Destroyer (2 squares) (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate iCoord(coordX,coordY); //Initial Destroyer coordinate
    cout<<"Please choose the ending coordinate for Destroyer (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate fCoord(coordX,coordY); //Final Destroyer coordinate
    
    samePointCheck=checkSamePoint(iCoord,fCoord);
    length=findLength(iCoord,fCoord);
    straightCheck=checkStraight(iCoord,fCoord);
    
    //Check validity of input
    while (samePointCheck==true || straightCheck ==false || length !=2){
        cout<<"Invalid output! Please enter a valid endpoint."<<endl;
        cin>> coordX >>coordY;
        Coordinate fCoord(coordX,coordY);
        samePointCheck=checkSamePoint(iCoord,fCoord);
        length=findLength(iCoord,fCoord);
        straightCheck=checkStraight(iCoord,fCoord);
    }
    
    //ASSIGN COORDINATE TO DESTROYER OBJECT!!!!
    
    cout<<"Please choose the starting coordinate for Submarine (3 squares) (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate iCoordS(coordX,coordY); //Initial Submarine coordinate
    cout<<"Please choose the ending coordinate for Submarine (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate fCoordS(coordX,coordY); //Final Submarine coordinate
    
    samePointCheck=checkSamePoint(iCoordS,fCoordS);
    length=findLength(iCoordS,fCoordS);
    straightCheck=checkStraight(iCoordS,fCoordS);
    
    //Check validity of input
    while (samePointCheck==true || straightCheck ==false || length !=3){
        cout<<"Invalid output! Please enter a valid endpoint."<<endl;
        cin>> coordX >>coordY;
        Coordinate fCoordS(coordX,coordY); //Final Submarine coordinate
        samePointCheck=checkSamePoint(iCoordS,fCoordS);
        length=findLength(iCoordS,fCoordS);
        straightCheck=checkStraight(iCoordS,fCoordS);
    }
    
    //ASSIGN COORDINATE TO SUBMARINE OBJECT!!!
    
    cout<<"Please choose the starting coordinate for Cruiser (3 squares) (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate iCoordC(coordX,coordY); //Initial Cruiser coordinate
    cout<<"Please choose the ending coordinate for Cruiser (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate fCoordC(coordX,coordY); //Final Cruiser coordinate
    
    samePointCheck=checkSamePoint(iCoordC,fCoordC);
    length=findLength(iCoordC,fCoordC);
    straightCheck=checkStraight(iCoordC,fCoordC);
    
    //Check validity of input
    while (samePointCheck==true || straightCheck ==false || length !=3){
        cout<<"Invalid output! Please enter a valid endpoint."<<endl;
        cin>> coordX >>coordY;
        Coordinate fCoordC(coordX,coordY); //Final Cruiser coordinate
        samePointCheck=checkSamePoint(iCoordC,fCoordC);
        length=findLength(iCoordC,fCoordC);
        straightCheck=checkStraight(iCoordC,fCoordC);
    }
    
    //ASSIGN COORDINATE TO CRUISER OBJECT!!!
  
    cout<<"Please choose the starting coordinate for Battleship (4 squares) (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate iCoordB(coordX,coordY); //Initial Battleship coordinate
    cout<<"Please choose the ending coordinate for Cruiser (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate fCoordB(coordX,coordY); //Final Battleship coordinate
    
    samePointCheck=checkSamePoint(iCoordB,fCoordB);
    length=findLength(iCoordB,fCoordB);
    straightCheck=checkStraight(iCoordB,fCoordB);
    
    //Check validity of input
    while (samePointCheck==true || straightCheck ==false || length !=4){
        cout<<"Invalid output! Please enter a valid endpoint."<<endl;
        cin>> coordX >>coordY;
        Coordinate fCoordB(coordX,coordY); //Final Battleship coordinate
        samePointCheck=checkSamePoint(iCoordB,fCoordB);
        length=findLength(iCoordB,fCoordB);
        straightCheck=checkStraight(iCoordB,fCoordB);
    }
    
    //ASSIGN COORDINATE TO BATTLESHIP OBJECT!!!
    
    cout<<"Please choose the starting coordinate for Carrier (5 squares) (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate iCoordCS(coordX,coordY); //Initial Carrier coordinate
    cout<<"Please choose the ending coordinate for Cruiser (x,y): "<<endl;
    cin>> coordX >>coordY;
    Coordinate fCoordCS(coordX,coordY); //Final Carrier coordinate
    
    samePointCheck=checkSamePoint(iCoordCS,fCoordCS);
    length=findLength(iCoordCS,fCoordCS);
    straightCheck=checkStraight(iCoordCS,fCoordCS);
    
    //Check validity of input
    while (samePointCheck==true || straightCheck ==false || length !=5){
        cout<<"Invalid output! Please enter a valid endpoint."<<endl;
        cin>> coordX >>coordY;
        Coordinate fCoordCS(coordX,coordY); //Final Carrier coordinate
        samePointCheck=checkSamePoint(iCoordCS,fCoordCS);
        length=findLength(iCoordCS,fCoordCS);
        straightCheck=checkStraight(iCoordCS,fCoordCS);
    }
    
    //ASSIGN COORDINATE TO CARRIER OBJECT!!!
    
    
    /*
     Implement function to check if input coordinate has already been taken!!
     Implement function to make AI chooses random positions to put its 5 ships
     Implement function for player and AI to take turn guessing one another ship until one side has lost all their ships
     */
    
    
    
    
    
    
    
    
    
    
    cout<<"Commander please input a coordinate between 0 and "<<rows-1<<" to attack!\n";
    while(shipRemaining!=0)
    {
        cout<<">>>>>Battle field<<<<<\n";
        Show();
        cout<<"Select weapon: Missle(1), Radar(2)  ";cin>>pos1;//add more functions!!!!
        if(pos1==1)
        {
            cout << "Please input coordinate: "; cin >> pos1 >> pos2;
            if(Attack(pos1,pos2))
                cout << "Hit!" << endl;
            else
                cout << "Sorry no ship at that position!" << endl;
        }
        else if(pos1==2)
        {
            ShowFinal();
        }
        acount++;
        shipRemaining=NumberOfShips();
        cout << "Number of units left: " << NumberOfShips() << endl;
        if (shipRemaining !=0){
        cout << "Do you want to quit (y/n)? "; cin >> prompt;
        if(prompt == 'y')
            break;
        }
    }
    cout<<"Perform "<<acount<<" moves, ";
    cout<<maxships-NumberOfShips()<<"ships are hit in the game.\n";
    cout << "Game over!" << endl;
    ShowFinal();
    return 0;
}
