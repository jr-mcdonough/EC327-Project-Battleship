#include "iostream"
#include"string"

using namespace std;

void Menu(){


    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;


    cout<<" _           _   _   _           _     _   "<<endl;
    cout<<"| |         | | | | | |         | |   (_)     "<<endl;
    cout<<"| |__   __ _| |_| |_| |  ___  ___| |__  _ _ __ "<<endl;
    cout<<"| '_ | / _` | __| __| | / _ |/ __| '_ || | '_ | " <<endl;
    cout<<"| |_) | (_| | |_| |_| ||  __/|__ | | | | | |_)|" <<endl;
    cout<<"|_.__/ |__,_||__||__|_||___||___/_| |_|_| .__/ "<<endl;
    cout<<"                                         | |    "<<endl;
    cout<<"                                         |_|    "<<endl;

    cout<<"          A game by the Navy Boys    "<<endl<<endl;


    cout<<"================================================="<<endl;
    cout<<"================================================="<<endl;

    cout<<"       <Press any key to continue>"<<endl;
    system("read");

    string username;
    cout<<"Admiral, what shall we refer to you as (1 word) ?:"<<endl;
    cin>>username;


    int choice;
    do{
    cout<<"                  Main Menu   "<<endl<<endl;
    cout<<"-------------------------------------------------"<<endl<<endl<<endl;
    cout<<"“Anchors aweigh, my boys, anchors aweigh.”"<<endl;
    cout<<"       — Joyce Eilers & Bob Lowden"<<endl<<endl;

    cout<<"                  1.Play"<<endl;
    cout<<"                  2.Credits"<<endl;
    cout<<"                  3.Exit game"<<endl<<endl;
    cout<<"          <Enter a number to proceed>"<<endl<<endl;
    cin>>choice;
    switch(choice){
        case 1:
    cout<<endl<<"        Welcome, Admiral "<<username<<endl<<endl;;
    break;
        case 2:
    cout<<endl<<"        By the Navy Boys"<<endl<<endl<<endl;
    cout<<"       <Press any key to return to main menu>"<<endl;
    system("read");
    break;
        case 3:
    cout<<endl<<"        Until next time, Admiral !"<<endl;
    exit(true);
    break;
    }
    }while(choice == 2 || choice ==3);
    }



int main(){
    Menu();
    return 0;

}