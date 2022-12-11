
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

void whileCheck(char& a) {
  cout << endl;
  cin.clear();
  cin.ignore(100,'\n');
  cout << "Do you wish to do it again? Y/N" << endl;
  cin >> a;

	while(a != 'y' && a != 'Y' && a != 'n'&& a != 'N') {
    cout << "Did you enter the correct response? If not, please enter your response again." << endl;
	  cin.clear();
    cin.ignore(100,'\n');
	  cin >> a;
  }
 
}

int main()
{
    Menu();
    srand(time(NULL));
    int ans;
    int difficultylevel; // 1 is easy; 2 is medium; 3 is hard
    char cont;
    

    battleshipGame abjects;
    
    // Make conditions to make sure user enter correct choices only
    
  // call member function intro for the intro
  sleep(1);
  do {
    //show difficulty levels
   
    
    cout<<endl<<"=========================================================="<<endl<<endl;
    cout<<"			Choose Difficulty Level"<<endl<<endl;
    cout<<"			1. Rookie Seaman"<<endl; //easy
    cout<<"			2. Seasoned Veteran"<<endl;
    cout<<"			3. Legendary Admiral"<<endl;
    cin>> difficultylevel;
    Instruction(difficultylevel);
    cin.clear();
    cin.ignore();

    if (difficultylevel <= 3 || difficultylevel > 0) {    
      //set difficulty level           
      abjects.initialize(difficultylevel);
    }
    else {
      cout << "INVALID SELECTION" << endl;
    }
    //check ammo and hits, if so end game.
    while(abjects.ammo > 0 && abjects.hits < 12) {
      cout << endl << "INSERT FIRING POSITION. LETTER first (column), and then the NUMBER (row). SPACING BETWEEN THEM IS OPTIONAL" << endl;
      //cin>> abjects;
      cin.clear();
      //cin.ignore();
      getline(cin, abjects);

      
      if(abjects.hity > 0 ) {
        cout <<" Previous shots: " <<endl;
        //linkedlist
        abjects.thelist();
        //show the ammo left and hits gotten
        abjects.theConsole();
        cout << abjects << endl;
      } else {
        cout << "TRY AGAIN" << endl;
      }
    }
    cout <<endl;
    cout << setfill(' ') << setw(25) << "GAME OVER." << endl;
   
    if(abjects.hits==12) {
      cout<< "Congratulations, Admiral. You have destroyed all the enemy." << endl;
    }
    else {
      cout<< "You were defeated. Our entire navy was swiftly destroyed by the enemy retaliation. Our seas are left to the mercy of the enemy." << endl;
    }
    cout << endl;
    whileCheck(cont);
  } while(cont == 'Y');
    system ("pause");
    
}



   
