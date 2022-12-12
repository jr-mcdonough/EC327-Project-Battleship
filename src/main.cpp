
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

//void whileCheck(char& a) {
/*void whileCheck(char a){
  char str;
  cout << endl;
  cin.clear();
  cin.ignore(100,'\n');
  cout << "Do you wish to do it again? Y/N" << endl;
  cin >> a;
  str=toupper(a);
	//while(a != 'y' && a != 'Y' && a != 'n'&& a != 'N') {
  while(str!='Y'||str!='N'){
    cout << "Did you enter the correct response? If not, please enter your response again." << endl;
	  cin.clear();
    cin.ignore(100,'\n');
	  cin >> a;
    str=toupper(a);
  }
 
}*/

int main()
{
    Menu();
    srand(time(NULL));
    int ans;
    int difficultylevel; // 1 is easy; 2 is medium; 3 is hard
    char cont;
    

    battleshipGame objects;
    
    // Make conditions to make sure user enter correct choices only
    
  // call member function intro for the intro
  sleep(1);
  bool difficultyValid=false;
  do {
    //show difficulty levels
    
    while(difficultyValid==false){
    cout<<endl<<"=========================================================="<<endl<<endl;
    cout<<"		Choose Difficulty Level"<<endl<<endl;
    cout<<"		1. Rookie Seaman"<<endl; //easy
    cout<<"		2. Seasoned Veteran"<<endl;
    cout<<"		3. Legendary Admiral"<<endl;
    cin>> difficultylevel;
    if(difficultylevel==1|| difficultylevel==2|| difficultylevel==3)
    {
      break;
    }
    else{
      cout<<"Enter again:"<<endl;
    }
    }
    Instruction(difficultylevel);
    cin.clear();
    cin.ignore();

    if (difficultylevel <= 3 && difficultylevel > 0) {    
      //set difficulty level           
      objects.initialize(difficultylevel);
    }
    else {
      cout << "INVALID SELECTION" << endl;
    }
    //check ammo and hits, if so end game.
    bool coordValid=false;
    bool canBreak;
    while(objects.ammo > 0 && objects.hits < 12) {
      cout << endl << "INSERT FIRING POSITION. LETTER first (column), and then the NUMBER (row). SPACING BETWEEN THEM IS OPTIONAL" << endl;
      //cin>> abjects;
      cin.clear();
      while(coordValid==false){
        canBreak=true;
      try{
          getline(cin, objects);
      }
      catch(int myNum){
        canBreak=false;
      }
        if(canBreak==true){
          break;
        }
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
    //whileCheck(cont);
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
    //system ("pause");
    
}



   
