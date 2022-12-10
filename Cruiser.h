#pragma once
#include "Ship.h"
#include "Coordinate.h"
#include <iostream>
using namespace std;
class Cruiser:public Ship{
    private:
        Coordinate *coord_ptr[3];
    public:
     Cruiser(){
        num_space=3;
        injured_square=num_space;
        sunk=false;
    }
    Cruiser(int x_in1,int y_in1,int x_in2,int y_in2,int x_in3,int y_in3){//array of coordinate objects to store coordinates of cruisers
        Coordinate *c1=new Coordinate(x_in1,y_in1);
        coord_ptr[0]=c1;
        Coordinate *c2=new Coordinate(x_in2,y_in2);
        coord_ptr[1]=c2;
        Coordinate *c3= new Coordinate(x_in3,y_in3);
        coord_ptr[2]=c3;
        num_space=3;
        injured_square=num_space;
        sunk=false;
    }
    bool attack(double x_in, double y_in);
    bool isHit();
    ~Cruiser(){
        for(int i=0;i<3;i++){
            delete coord_ptr[i];
        }
        cout<<"Cruiser destroyed"<<endl;
    }



};