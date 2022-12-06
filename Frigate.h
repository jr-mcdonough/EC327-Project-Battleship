#include "Ship.h"
class Frigate:public Ship{
    public:
        
    Frigate(){
        num_space=1;
        injured_square=num_space;
    }
    Frigate(int x_in,int y_in){
        shiploc.x=x_in;
        shiploc.y=y_in;
        num_space=3;
        injured_square=num_space;
    }
    bool attack(int x_in, int y_in);
    bool isHit();
};