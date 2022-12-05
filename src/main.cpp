
#include <iostream>
#include <ctime>

using namespace std;


int const rows=10;
int const columns=rows;

int maxships=10;

int matrix[rows][columns];

//This function is used to reset the board for the game
void Clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j <columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

//This function is used to show the board to the player
void Show()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
        {
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
 SetShips(): The default board is a matrix filled with zeros as shown in the function Show(), the function SetShip() will choose a random location (x,y) on the board to place a ship there and replaces the value of 0 by 1 at location (x,y). It will loop until it has placed the number of ships according to the int maxships value.
 */
void SetShips()
{
    //Generate random ships on board
    int s = 0;
    while(s < maxships)
    {
        //generate a random location on the board
        int x = rand() % rows;
        int y = rand() % columns;
        
        //Check if there is already a ship in that location
        if(matrix[x][y] != 1)
        {
            //If that location is free, denotes that location with number 1
            s++;
            matrix[x][y] = 1;
        }
    }
}

/*
 Attack(): This functions check if the location that the player chooses has a ship or not. If there is a ship at location, change that location value from 1 to 2 and return true, else if there is no ship return false.
 */
bool Attack(int x,int y)
{
    if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

/*
 NumberOfShips(): This functions checks the number of ships remaining on the board after a player has chooses a location to attack.
 */
int NumberOfShips()
{
    int counter=0;
    
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j <columns; j++)
        {
            if(matrix[i][j] == 1)
                counter++;
        }
    }
 
    return counter;
}

/*
 Game starts with the computer generates random ship on the board, the player is asked to choose a location and the game repeat until there are no ships remaining or the player surrenders.
 */
int main(){
    
    srand(time(NULL));
        Clear();
        SetShips();
        int pos1,pos2;
        char input;
    //Check number of ships
    int shipRemaining=NumberOfShips();
    
    cout <<"Welcome to Battleship"<<endl;
    
        while(shipRemaining!=0)
        {
            cout << "Please input location: "; cin >> pos1 >> pos2;
            if(Attack(pos1,pos2)){
                cout << "Ship sunk! :)" << endl;
            }
            else{
                cout << "Sorry no ship at that position!" << endl;
            }
            
            shipRemaining=NumberOfShips();
            
            cout << "Number of ships left: " <<shipRemaining << endl;
            
            
            //If there are still ship left, ask player for surrender
            if (shipRemaining !=0){
            cout << "Do you want to surrender (y/n)? "; cin >> input;
                if(input == 'y'){
                break;
                }
            }
            
        }
    
        cout << "Game over!" << endl;
        Show();
        return 0;
    return 0;
}



