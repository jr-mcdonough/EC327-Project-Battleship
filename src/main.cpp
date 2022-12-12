//use make Play to compile.
//the complied file is called Play

#include "menu.h"
#include "Instructions.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib> 
#include "battleshipgame.h"



using namespace std;


int main()
{
    Menu();//prints out the menu of game
    srand(time(NULL));//set seed
    int ans;
    int difficultylevel; // 1 is easy; 2 is medium; 3 is hard
    char cont;
    

    battleshipGame objects;
    
    // Make conditions to make sure user enter correct choices only
    
  // call member function intro for the intro
  sleep(1);
  do {
    //show difficulty levels
  
    
    cout<<endl<<"=========================================================="<<endl<<endl;
    cout<<"		Choose Difficulty Level"<<endl<<endl;
    cout<<"		1. Rookie Seaman"<<endl; //easy
    cout<<"		2. Seasoned Veteran"<<endl;
    cout<<"		3. Legendary Admiral"<<endl;
    cin>> difficultylevel;
    Instruction(difficultylevel);//input the the difficulty level
    cin.clear();
    cin.ignore();

    if (difficultylevel <= 3 && difficultylevel > 0) {    
      //set difficulty level           
      objects.initialize(difficultylevel);
    }
    else {
      cout << "INVALID SELECTION" << endl;//error checking
    }
    //check ammo and hits, if so end game.
    while(objects.ammo > 0 && objects.hits < 12) {
      cout << endl << "INSERT FIRING POSITION. LETTER first (column), and then the NUMBER (row). SPACING BETWEEN THEM IS OPTIONAL" << endl;
      //cin>> abjects;
      cin.clear();
      try{
          getline(cin, objects);
      }
      catch(string mystring){
          getline(cin,objects);
      }
      

      cout<<"=========================================================="<<endl;
      if(objects.hity > 0 ) {
        cout <<" Previous shots: " <<endl;
        //linkedlist
        objects.thelist();
        //show the ammo left and hits gotten
        objects.theConsole();
        cout << objects << endl;
      } else {
        cout << "TRY AGAIN" << endl;
      }
    }
    cout <<endl;
    cout << setfill(' ') << setw(25) << "GAME OVER." << endl;
   
    if(objects.hits==12) {
      cout<< "Congratulations, Admiral. You have destroyed all the enemy." << endl;
    }
    else {
      cout<< "You were defeated. Our entire navy was swiftly destroyed by the enemy retaliation. Our seas are left to the mercy of the enemy." << endl;
    }
    cout << endl;
    
    cout << "Do you wish to do it again? Y/N" << endl;
    cin >> cont;
    if(cont=='N'||cont=='n'){
      exit(true);
      
    }
    while(cont!='Y'&&cont!='N'&&cont!='y'&&cont!='n'){
      cout<<"Input again:"<<endl;
      cin>>cont;
    }
  } while(cont == 'Y'||cont=='y');
    
    
}



   
