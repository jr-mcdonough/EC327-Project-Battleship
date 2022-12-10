#include "Instructions.h"
#include <iostream>


void Instruction(int mode){
 cout<<"=================================================================================================================="<<endl<<endl;
 cout<<endl<<"Admiral, we have received intel that several enemy ships were spotted patrolling the waters of our country."<<endl<<endl;
 cout<<"As the commander of our navy, you are tasked with defending our sea by any means necessary."<<endl<<endl<<endl;
 cout<<"<Press any key to continue> "<<endl<<endl;
    system("read");
    cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"Our friends in the airforce has indicated the location of where the enemy ships might be located."<<endl<<endl;
     //show map

    cout<<"0| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"1| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"2| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"3| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"4| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"5| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"6| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"7| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"8| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"9| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"  ___________________"<<endl;
    cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl<<endl;

    cout<<"0 means no ship or hidden ship."<<endl<<endl;
    cout<<"<Press any key to continue> "<<endl;
    system("read");
    cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"If you manage to hit a ship, the spot will be represented with 'X'. "<<endl<<endl;
    //show map demo hit ship

    cout<<"0| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"1| 0 X 0 0 0 X 0 0 0 0 "<<endl;
    cout<<"2| 0 X 0 0 0 X 0 0 0 0 "<<endl;
    cout<<"3| 0 0 0 0 0 X 0 0 0 0 "<<endl;
    cout<<"4| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"5| 0 0 X 0 0 0 0 0 X 0 "<<endl;
    cout<<"6| 0 0 X 0 0 0 0 0 X 0 "<<endl;
    cout<<"7| 0 0 0 0 0 0 0 0 X 0 "<<endl;
    cout<<"8| 0 0 0 0 X 0 0 0 0 0 "<<endl;
    cout<<"9| 0 0 0 0 X 0 0 0 0 0 "<<endl;
    cout<<"  ___________________"<<endl;
    cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl<<endl;

    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"Previous missile attempt that did not hit an enemy ship will be marked with '1'."<<endl<<endl;

    cout<<"0| 0 0 0 1 0 0 0 0 1 0 "<<endl;
    cout<<"1| 0 X 0 0 0 X 0 0 0 0 "<<endl;
    cout<<"2| 0 X 0 0 0 X 0 0 1 0 "<<endl;
    cout<<"3| 0 1 0 0 0 X 0 0 0 0 "<<endl;
    cout<<"4| 0 0 0 0 0 0 0 0 0 0 "<<endl;
    cout<<"5| 0 0 X 0 0 0 0 0 X 0 "<<endl;
    cout<<"6| 0 0 X 0 0 1 0 0 X 0 "<<endl;
    cout<<"7| 0 1 0 0 0 1 0 0 X 0 "<<endl;
    cout<<"8| 0 1 0 0 X 0 0 0 0 0 "<<endl;
    cout<<"9| 0 0 0 0 X 0 1 1 0 0 "<<endl;
    cout<<"  ___________________"<<endl;
    cout<<"   0 1 2 3 4 5 6 7 8 9"<<endl<<endl;


    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"You will have 5 different ship types. Their location is your choice to make. they are the following: "<<endl<<endl;
    cout<<"Destroyer - 2 squares"<<endl;
    cout<<"Submarine - 3 squares"<<endl;
    cout<<"Cruiser - 3 squares"<<endl;
    cout<<"Battleship - 4 squares"<<endl;
    cout<<"Carrier - 5 squares"<<endl<<endl;


    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"Please note that you can only position the ships vertically or horizontally in a straight line and with correct dimension."<<endl<<endl;

    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    // Now check for mode. Easy mode (1)- no AI, Medium (2) - Dumb AI -random, Hard (3)- Smarter AI
    if(mode == 1){
        cout<<endl<<"Admiral, your job is to find out the positions of all the enemy ships as quick as possible."<<endl;
        cout<<"You are aimed with as much missiles as you would like to employ."<<endl<<endl;
        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        exit(true);
    }else if(mode == 2){

        cout<<endl<<"Admiral, your job is to find out the position of all the enemy ships as quickly as possible. "<<endl;
        cout<<"Beware, the enemy is aware of our presence and will retaliate."<<endl<<endl;


        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"You are aimed with 34 missiles and unlimited radar."<<endl;
        cout<<"Radar reveals general location of enemy ship(s) but never their definite coordinates."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

    }
    else if(mode == 3){

        cout<<endl<<"Admiral, your job is to find out the position of all the enemy ships as quickly as possible. "<<endl;
        cout<<"Beware, the enemy is aware of our presence and will retaliate."<<endl<<endl;


        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"You are aimed with 34 missiles and 10 uses of radar."<<endl;
        cout<<"Radar reveals general location of enemy ship(s) but never their definite coordinates."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

    }





}

