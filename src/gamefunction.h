#pragma once
#include <iostream>
#include <ctime>
#include "coordinate.h"
#include"string"

const int rows = 10;
const int elements = 10;
 
bool checkSamePoint(const Coordinate c1, const Coordinate c2);
int findLength(const Coordinate c1, const Coordinate c2);
bool checkStraight(const Coordinate c1, const Coordinate c2);
void Clear();
void Show();
void ShowFinal();
int NumberOfShips();
void SetCruisers();
void SetFrigate();
bool Attack(int x,int y);
