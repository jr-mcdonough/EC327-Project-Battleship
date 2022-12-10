#include "gamefunction.h"
#include "menu.h"
#include "Instructions.h"

using namespace std;
//0 is no ship or not visible
//1 is nonvisible ship
//2 is injured ship
//Can add file io that store and read highest scores


int main()
{
    Menu();
    // Make cout to ask users to input difficulties level
    Instructions(1);
    srand(time(NULL));
    Clear();
    SetCruisers();
    SetFrigate();
    int maxships = 10;
    int pos1,pos2,acount=0;
    char prompt;
    bool samePointCheck;
    bool straightCheck;
    int length;
    
    //Check number of ships
        int shipRemaining=NumberOfShips();
        
    
    
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
