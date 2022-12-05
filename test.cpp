#include <iostream>
#include <ctime>
using namespace std;
//0 is no ship or not visible
//1 is nonvisible ship
//2 is injured ship
//Can add file io that store and read highest scores
const int rows = 10;
const int elements = 10;
 
int maxships = 10;
 
int matrix[rows][elements];
 
void Clear()//reset the map
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
 
void Show()//user show, only show injured or visible ships
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
 
void SetShips()
{
    int s = 0;
    while(s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        if(matrix[x][y] != 1)
        {
            s++;
            matrix[x][y] = 1;
        }
    }
}
 
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
    srand(time(NULL));
    Clear();
    SetShips();
    int pos1,pos2,acount=0;
    char prompt;
    cout<<">>>Welcome to Battleship!<<<\n";
    cout<<"0 means no ship or hidden ship, 2 means injured ship.\n";
    cout<<"Goal is to hit every ship under minimum moves.\n";
    cout<<"Commander please input a coordinate between 0 and "<<rows-1<<" to attack!\n";
    while(1)
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
        cout << "Number of ships left: " << NumberOfShips() << endl;
        cout << "Do you want to quit (y/n)? "; cin >> prompt;
        if(prompt == 'y')
            break;
    }
    cout<<"Perform "<<acount<<" moves, ";
    cout<<maxships-NumberOfShips()<<"ships are hit in the game.\n";
    cout << "Game over!" << endl;
    ShowFinal();
    return 0;
}