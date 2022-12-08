#include "Coordinate.h"
Coordinate::Coordinate()
{
            x=0;
            y=0;

}
Coordinate::Coordinate(int x_in,int y_in)
{
            x=x_in;
            y=y_in;
}
double Coordinate::GetX(){
    return x;
}
double Coordinate::GetY(){
    return y;
}
ostream &operator<<(ostream &out, Coordinate &c1){
    out<<"("<<c1.x<<","<<c1.y<<")"<<endl;
    return out;
}