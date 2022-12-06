#include "Frigate.h"
#include <iostream>
using namespace std;
bool Frigate::attack(int in_x,int in_y){
        if(in_x==shiploc.x && in_y==shiploc.y){
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