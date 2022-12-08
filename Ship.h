#pragma once
#include "Coordinate.h"
class Ship{
    protected:
        int num_space; //number of space the ship takes
        int injured_square; // how many squares ship have been hit
        bool sunk=false;
        Coordinate shiploc;
        
    public:
    //void SelfDraw(char *ptr); 
    Ship();
    virtual bool isHit()=0;
    virtual bool attack(int x, int y)=0;
    
    ~Ship(){
        cout<<"Ship deleted"<<endl;
    }



};