#include "Cruiser.h"
bool Cruiser::attack(double in_x, double in_y){
    bool hitsquare=false;
    for(int i=0;i<num_space;i++){
        if(coord_ptr[i]->GetX()==in_x && coord_ptr[i]->GetY()==in_y){
            cout<<"Hit"<<endl;
            injured_square=injured_square-1;
            hitsquare=true;
        }
    }
    if(hitsquare==false){
        return false;
    }
    else if(hitsquare==true)
    {
        return true;
    }
}
bool Cruiser::isHit(){
    if(injured_square==0){
        sunk=true;
        return true;
    }
    else{
        return false;
    }
}