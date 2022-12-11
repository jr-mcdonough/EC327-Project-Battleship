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

    cout<<"  | A | B | C | D | E | F | G | H |"<<endl;
    cout<<" 1| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 2| * | * | * | * | * | * | * | * | "<<endl;
    cout<<" 3| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 4| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 5| * | * | * | * | * | * | * | * | "<<endl;
    cout<<" 6| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 7| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 8| * | * | * | * | * | * | * | * |"<<endl<<endl;
  

    cout<<"* means no ship or hidden ship."<<endl<<endl;
    cout<<"<Press any key to continue> "<<endl;
    system("read");
    cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"If you manage to hit a ship, the spot will be represented with 'S'. "<<endl<<endl;
    //show map demo hit ship

    cout<<"  | A | B | C | D | E | F | G | H |"<<endl;
    cout<<" 1| * | S | * | * | * | * | * | * |"<<endl;
    cout<<" 2| * | S | * | * | * | * | * | * | "<<endl;
    cout<<" 3| * | * | S | * | * | * | * | * |"<<endl;
    cout<<" 4| * | * | S | * | * | * | * | * |"<<endl;
    cout<<" 5| * | * | S | * | * | S | S | * | "<<endl;
    cout<<" 6| * | * | * | * | * | * | * | * |"<<endl;
    cout<<" 7| * | * | * | * | S | * | * | * |"<<endl;
    cout<<" 8| * | * | * | * | S | * | * | * |"<<endl<<endl;

    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"Previous missile attempt that did not hit an enemy ship will be marked with '%'."<<endl<<endl;

    cout<<"  | A | B | C | D | E | F | G | H |"<<endl;
    cout<<" 1| * | S | * | * | * | * | % | % |"<<endl;
    cout<<" 2| % | S | * | * | * | * | * | * | "<<endl;
    cout<<" 3| % | * | S | % | * | * | * | * |"<<endl;
    cout<<" 4| * | * | S | * | * | * | * | * |"<<endl;
    cout<<" 5| * | * | S | * | * | S | S | * | "<<endl;
    cout<<" 6| * | * | * | * | * | * | % | * |"<<endl;
    cout<<" 7| * | % | * | * | S | * | % | * |"<<endl;
    cout<<" 8| * | % | * | * | S | * | * | * |"<<endl<<endl;


    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"The enemy have 3 different ship types. They are the following: "<<endl<<endl;
    cout<<"Submarine - 3 squares"<<endl;
    cout<<"Battleship - 4 squares"<<endl;
    cout<<"Carrier - 5 squares"<<endl<<endl;
    cout<<"There are atleast 3 enemy ships being spotted"<<endl<<endl;


    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    cout<<endl<<"Please note that the ships are only positioned vertically or horizontally in a straight line."<<endl<<endl;

    cout<<"<Press any key to continue> "<<endl<<endl;

    system("read");
cout<<"=================================================================================================================="<<endl<<endl;
    // Now check for mode. The harder the difficulty, the larger the map
    if(mode == 1){
        cout<<endl<<"Admiral, your job is to find out the positions of all the enemy ships as quickly as possible."<<endl;
        cout<<"You are armed with 20 missiles to destroy the enemy."<<endl<<endl;
        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        
    }else if(mode == 2){

        cout<<endl<<"Admiral, your job is to find out the position of all the enemy ships as quickly as possible. "<<endl;
        cout<<"Beware, the enemy is spreaded out over a wide area. "<<endl<<endl;


        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"You are armed with 20 missiles to destroy the enemy. Use them wisely."<<endl<<endl;
        

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

    }
    else if(mode == 3){

        cout<<endl<<"Admiral, your job is to find out the position of all the enemy ships as quickly as possible. "<<endl;
        cout<<"Beware, the enemy is spreaded out over a large area and can be anywhere."<<endl<<endl;


        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"You are armed with 20 missiles to destroy the enemy. Use them wisely."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

        cout<<endl<<"Good luck Admiral, the country awaits your victory."<<endl<<endl;

        cout<<"<Press any key to continue> "<<endl<<endl;

        system("read");

    }





}

