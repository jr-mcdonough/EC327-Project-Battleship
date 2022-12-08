#include "Frigate.h"
#include <iostream>
using namespace std;
bool Frigate::attack(int x_in,int y_in){
        if(x_in==shiploc.x && y_in==shiploc.y){
            cout<<"Hit frigate"<<endl;
            injured_square=injured_square-1;
            return true;
        }
        else{
            return false;
            
        }
}
bool Frigate::isHit(){
    if(injured_square==0){
        cout<<"Ship sunk"<<endl;
        sunk=true;
        return true;
    }
    else{
        return false;
    }
}