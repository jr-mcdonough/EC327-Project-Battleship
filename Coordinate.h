#pragma once
#include <iostream>
#include <cmath>
#include <fstream>
#include <ostream>
#pragma once
using namespace std;
class Coordinate{
    public:
        int x;
        int y;
        Coordinate();
        Coordinate(int x_in,int y_in);
        double GetX();
        double GetY();
};
ostream &operator<<(ostream &out,  Coordinate &c1);

