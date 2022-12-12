#include "menu.h"

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

    cout<<"       <Press ENTER to continue>"<<endl;
    system("read");

    string username;
    bool validstring=false;
   
    while(validstring==false){
         cout<<"Admiral, what shall we refer to you as (1 word) ?:"<<endl;
        bool hasSpace=false;
        getline(std::cin,username);
        int stringlen=username.size();
        for(int i=0;i<=stringlen;i++){
            if(username[i]==' '){
                hasSpace=true;
                
            }
        }
        if(hasSpace==false){
            validstring=true;
        }
    }
   
    
    
    

    int choice;
    do{
    cout<<"                  Main Menu   "<<endl<<endl;
    cout<<"-------------------------------------------------"<<endl<<endl<<endl;
    cout<<"“Anchors aweigh, my boys, anchors aweigh.”"<<endl;
    cout<<"       — Joyce Eilers & Bob Lowden"<<endl<<endl;
    bool choiceValid=false;
    while(choiceValid==false){
    cout<<"                  1.Play"<<endl;
    cout<<"                  2.Credits"<<endl;
    cout<<"                  3.Exit game"<<endl<<endl;
    
    cout<<"          <Enter a number to proceed>"<<endl<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<endl<<"        Welcome, Admiral "<<username<<endl<<endl;;
        choiceValid=true;
        break;
        case 2:
        cout<<endl<<"        By the Navy Boys"<<endl<<endl<<endl;
        cout<<"       <Press ENTER to return to Main Menu >"<<endl;
        system("read");
        break;
        case 3:
        cout<<endl<<"        Until next time, Admiral !"<<endl;
        exit(true);
        choiceValid=true;
        break;
        default:
        cout<<"Enter again:"<<endl;
        break;
    }
    }
    }while(choice == 2 || choice ==3);
    
    }
