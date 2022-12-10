#include "Console.h"
#include <iostream>
#include <list>
using namespace std;
void Console::Clear()//This function is used to reset the board for the game

{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            matrix[i][j] = 0;
        }
    }
}
 
void Console::Show()//This function is used to show the board to the player

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

void Console::ShowFinal()//the actual location of ship
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

int Console::NumberOfShips()//get the number of ships
{
    /*int c = 0;
 
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            if(matrix[i][j] == 1)
                c++;
        }
    }
 
    return c;*/
    return num_ships;
}
 
void Console::SetCruisers()//3 units length,2 cruisers per game
{
                //generate a random location on the board
        int x = rand() % rows;
        int y = rand() % elements;
             //Check if there is already a ship in that location
        matrix[x][y] = 1;
		matrix[x+1][y] = 1;
		matrix[x+2][y] = 1;
        Cruiser *cruiser1 = new Cruiser(x,y,x+1,y,x+2,y);
        cruiser_ptr.push_back(cruiser1);
        ship_ptr.push_back(cruiser1);
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
        Cruiser *cruiser2 = new Cruiser(z,h,z+1,h,z+2,h);
        cruiser_ptr.push_back(cruiser2);
        ship_ptr.push_back(cruiser2);
        
    
}

void Console::SetFrigate()//SetShips(): The default board is a matrix filled with zeros as shown in the function Show(), the function SetShip() will choose a random location (x,y) on the board to place a ship there and replaces the value of 0 by 1 at location (x,y). It will loop until it has placed the number of ships according to the int maxships value.
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
            matrix[x][y] = 1;
            Frigate *newfrigate= new Frigate(x,y);
            frigate_ptr.push_back(newfrigate);
            ship_ptr.push_back(newfrigate);
            //ship_ptr[s]=newfrigate;
            num_frigates+=1;
        }
		else
		{
			x = rand() % rows;
        	y = rand() % elements;
			

			s++;
		}
    }
}

  

bool Console::ShipAttack(int x,int y)// checks if attack hits ship, if it does then update accordingly
{   
    bool hitship=false;
    bool hitcruiser=false;
    bool hitfrigate=false;
    /*for(int i=0;i<num_cruisers;i++){
        hitcruiser=cruiser_ptr[i]->attack(x,y);
        if(hitcruiser==true){
            hitship=true;
            num_ships=num_ships-1;
        }
        else
        {
            hitship=false;
        }
    }*/
    std::list<Frigate*>::iterator frigateIt;
    for(frigateIt=frigate_ptr.begin();frigateIt!=frigate_ptr.end();++frigateIt){
        hitfrigate=(*frigateIt)->attack(x,y);
        if(hitfrigate==true){
            hitship=true;
            cout<<"Frigate true"<<endl;
            num_ships=num_ships-1;
            num_frigates=num_frigates-1;
            break;
        }
        else if(hitfrigate==false){
            hitship=false;
        }
    }
    
    std::list<Cruiser*>::iterator cruiserIt;
    for(cruiserIt=cruiser_ptr.begin();cruiserIt!=cruiser_ptr.end();++cruiserIt){
        hitcruiser=(*cruiserIt)->attack(x,y);//return true if a ship is hit at coordinate (x,y)
        if(hitcruiser==true){
            hitship=true;
            cout<<"Hit cruiser"<<endl;//print message for debugging
            
            
        }
        else{
            hitship=false;
        }
        if((*cruiserIt)->isHit()==true){//return true if all squares are hit
            cout<<"Cruiser sunk"<<endl;
            num_ships=num_ships-1;//reduce number of ships by 1
            num_cruisers=num_cruisers-1;//reduce number of cruiser by 1
        }
        else if((*cruiserIt)->isHit()==false){
            cout<<"Cruiser hit but still survives"<<endl;
        }
    }
    /*for(int j=0;j<num_frigates;j++){
        hitfrigate=frigate_ptr[j]->attack(x,y);
        if(hitfrigate==false){
            hitship=true;
        }
        else{
            hitship=false;
        }
    }*/

    /*if(matrix[x][y] == 1)
    {
        matrix[x][y] = 2;
        return true;
    }
    return false;*/
    return hitship;
}
int Console::GetFrigates(){//return number of frigates(for testing)
    return num_frigates;
}
void Console::setShip(){//initiliaze grid with ships
    SetCruisers();
    SetFrigate();
}
 