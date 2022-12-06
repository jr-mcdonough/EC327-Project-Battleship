#include "Coordinate.h"
class Ship{
    protected:
        int num_space; //number of space the ship takes
        int injured_square; // how many squares ship have been hit
        bool sunk;
        Coordinate shiploc;
    public:
    //void SelfDraw(char *ptr); 
    virtual bool isHit()=0;
    virtual bool attack(int x, int y)=0;
    




};