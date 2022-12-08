#pragma once
#include <iostream>
#include <time.h>
using namespace std;
#include "Console.h"
#include "Ship.h"
#include "Frigate.h"
#include "Cruiser.h"
#include "Coordinate.h"






int main()
{
    int maxships=10;
    Console console1;
    srand(time(NULL));
    console1.Clear();
   // console1.SetCruisers();
	console1.SetFrigate();
    int pos1,pos2,acount=0;
    char prompt;
    cout<<">>>Welcome to Battleship!<<<\n";
    cout<<"0 means no ship or hidden ship, 2 means injured ship.\n";
    cout<<"Goal is to hit every ship under minimum moves.\n";
    cout<<"Commander please input a coordinate between 0 and "<<rows-1<<" to attack!\n";
    while(1)
    {
        cout<<">>>>>Battle field<<<<<\n";
        console1.Show();
        cout<<"Select weapon: Missle(1), Radar(2)  ";cin>>pos1;//add more functions!!!!
        if(pos1==1)
        {
            cout << "Please input coordinate: "; 
            cin >> pos1 >> pos2;
            if(console1.ShipAttack(pos1,pos2))
                cout << "Hit!" << endl;
            else{
                cout << "Sorry no ship at that position!" << endl;
            }
            cout<<"Frigates:"<<console1.GetFrigates()<<endl;
        }
        else if(pos1==2)
        {
            console1.ShowFinal();
            cout<<"Frigates:"<<console1.GetFrigates()<<endl;
        }
        acount++;
        cout << "Number of units left: " << console1.NumberOfShips() << endl;
        cout << "Do you want to quit (y/n)? "; cin >> prompt;
        if(prompt == 'y')
            break;
    }
    cout<<"Perform "<<acount<<" moves, ";
    cout<<maxships-console1.NumberOfShips()<<"ships are hit in the game.\n";
    cout << "Game over!" << endl;
    console1.ShowFinal();
    return 0;
}


