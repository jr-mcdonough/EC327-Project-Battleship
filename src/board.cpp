#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib> 
#include <sstream> 
#include "battleshipgame.h"


using namespace std;

board::board()
{
diffXSetter = 0;
diffYSetter = 0;
hitx = 0;
hity = 0;
}

board::~board()
{
delete [] *hhh;
delete [] *temp;
delete first;
delete last;
delete newnode;
}

void board::initializeBoard()
{
     hhh = new char* [diffYSetter+1];
     for(int row =0; row <= diffYSetter+1; row++)
     hhh[row] = new char[diffXSetter+1];
     
     temp = new char* [diffYSetter+1];
     for(int row =0; row <= diffYSetter+1; row++)
     temp[row] = new char[diffXSetter+1];
}

void board::populate()
{     
     for(int row = 0; row <= diffYSetter; row++)
      for(int col = 0; col <= diffXSetter; col++)
       hhh[row][col] = '*';
       
       for(int row = 0; row <= diffYSetter; row++)
      for(int col = 0; col <= diffXSetter; col++)
       temp[row][col] = ' ';
}

void board::printBoard()
{
     for(int row=0; row <=diffYSetter; row++)
     { 
             if(row == 0)
            { cout << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {cout << " " << row << "|";}
             else 
             {cout << row << "|";}
      for(int col=1; col <= diffXSetter; col++)
      {
              if(row==0)
             { cout << " " << char(64+col) << ' ' << "|";}
              else
             { cout << ' ' << hhh[row][col] << ' ' << "|";}
      }
              cout << endl;        
     }
}

void board::showActualBoard()
{
     for(int row=0; row <=diffYSetter; row++)
     { 
             if(row == 0)
            { cout << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {cout << " " << row << "|";}
             else 
             {cout << row << "|";}
      for(int col=1; col <= diffXSetter; col++)
      {
              if(row==0)
             { cout << " " << char(64+col) << ' ' << "|";}
              if(row>0)
             { cout << ' ' << temp[row][col] << ' ' << "|";}
      }
              cout << endl; 
}
}

void board::setBoard(int level)
{
    if(level == 1)
    {
    diffXSetter = 8;
    diffYSetter = 8;
}
    if (level == 2)
      {
    diffXSetter = 10;
    diffYSetter = 10;
}
    if (level == 3)
      {
    diffXSetter = 12;
    diffYSetter = 12;
}
}


bool board::placeship(int x, int y, int dir, int size,int lvl,char t)
{
     int i, p,row,col,bsize;
     row=x;
     col=y;
     if(lvl == 1)
     {
            bsize = 8;
     }
        else if(lvl == 2)
        {

            bsize = 10;
        }
            else
            {
                bsize = 12;
            }
            
            if(row<0 || row> bsize || col >= bsize)
            {
                return false;
            }
            if(dir == 1)
            {
                if(row + size>= bsize)
                {
                    return false;
                }
                for(int i = row; i <row+size;i++)
                {
                    if(temp[i][col] != ' ')
                    {
                        return false;
                    }
                }
                for(int i = row; i<row+size;i++)
                {
                    temp[i][col]=t;
                }
            }
            else if(dir == 2)
            {
                if(col+size>=bsize)
                {
                    return false;
                }
                for(int j = col; j<col+size;j++)
                {
                    if(temp[row][j] != ' ')
                    {
                        return false;
                    }
                }
                for(int j = col; j<col+size;j++)
                {
                    temp[row][j]=t;
                }
            }
            return true;
        }

void board::checkhit(char x, int y)
{
     x = toupper(x);
     if(temp[y][static_cast<int>(x-64)] == 'S'||temp[y][static_cast<int>(x-64)] == 'D'||temp[y][static_cast<int>(x-64)] == 'C')
     {
      hhh[y][static_cast<int>(x-64)] = temp[y][static_cast<int>(x-64)];
      hit++;
      ammo--;
      miss = 1;
     }
     else
     {
     hhh[y][static_cast<int>(x-64)] = '%';
     ammo--;
     miss = 2;
     }
     dolinkedlist();
}



void board::setCoords(char x, int y){
  hitx = x;
  hity = y;

  if(static_cast<int>(hitx-64) <= 32 + diffXSetter && hity <= diffYSetter ){
    if(checklinkedlist()){
      checkhit(hitx,hity);
    } else {
      cout << ">>>REPORT<<<:We have tried this location before, Admiral. Select another spot." << endl;
    }
  } else {
    cout << ">>>ERROR<<< The enemy is NOT within this area. Please use the intel we have" << endl;
  }

}

istream& getline (istream& obj, board& xxx)//overload getline operator
{
  int num=1;
  getline(obj, xxx.hitstr);
  if(xxx.hitstr.length()==0){
      cout<<"you entered nothing"<<endl;
      throw(num);
  }
  
  for(int i = 0; i < xxx.hitstr.length(); i++){
    if(xxx.hitstr[i] == ' ') {
      xxx.hitstr.erase(i,1);
    }
  }

  if(xxx.hitstr.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") > 0){
    stringstream yy(xxx.hitstr.substr(1));
    int y = 0; 
    if(isdigit(xxx.hitstr[0])!=0){
            cout<<"Enter a LETTER  then a NUMBER please:"<<endl;
            throw(num);
      }
    yy >> y; 
    xxx.setCoords(xxx.hitstr[0], y);

  } else {
    cout << "INVALID INPUT";
  }
    
  return obj;
}


istream& operator>>(istream& obj, board& xloc)
{
  obj >> xloc.hitx >> xloc.hity;
      
// check to see if the user input values are on the board/and if the spot has been hit previously.
      if(static_cast<int>(xloc.hitx-64) <= 32 + xloc.diffXSetter && xloc.hity <= xloc.diffYSetter ){
        if(xloc.checklinkedlist()){
          xloc.checkhit(xloc.hitx,xloc.hity);
        } else {
          cout << ">>>REPORT: We have tried this location before, Admiral. Select another spot.<<<" << endl;
        }
      } else {
        cout << ">>>ERROR: The enemy is not within this area, Admiral<<<" << endl;
      }
      return obj;
}

ostream& operator<<(ostream& obj, const board& xxx)
{

       for(int row=0; row <=xxx.diffYSetter; row++)
     { 
             if(row == 0)
            { obj << ' ' << ' ' << "|";}
             else if (row > 0 && row < 10)
             {obj << " " << row << "|";}
             else 
             {obj << row << "|";}
      for(int col=1; col <= xxx.diffXSetter; col++)
      {
              if(row==0)
             { obj << " " << char(64+col) << ' ' << "|";}
              else
             { obj << ' ' << xxx.hhh[row][col] << ' ' << "|";}
      }
              obj << endl;        
     }
     obj << "You have hit coordinates: " << "(" << static_cast<char>(toupper(xxx.hitx));
     obj << "," << xxx.hity << ")" << endl;
     
     return obj;
}

void board::theConsole()
{//display ammo
cout << endl << endl;
cout << "Ammo: " << ammo;
cout << setfill(' ') << setw(diffXSetter*2+5) << ' ' << "Hits: " << hit <<endl;     
}

void board::dolinkedlist() 
{
     newnode = new nodeType;

     newnode->x = toupper(hitx);
     newnode->y = hity;
     newnode->hom = miss;
     newnode->link = NULL;
     
     if (first == NULL)
     {
         first = newnode;
         last = newnode;
     }
     else
     {
         last->link = newnode;
         last = newnode;
     }  
}

void board::printlinkedlist()
{
 nodeType *current;
 
 current = first;
 while (current != NULL)
{   // show hit or miss
 switch(current->hom)
 {
  case 1:
     cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "HIT" << endl;       
     break;
 case 2:
      cout << "Coordinates: " << "(" << current->x << ", " << current->y << ") " << "MISS" << endl; 
      break;  
 }
    current = current->link;
}
}
bool board::checklinkedlist(){
  nodeType *current;
  current = first;
  
  while (current != NULL) {
    if(current->x == toupper(hitx) && current->y == hity){
      return false;
    }
    current = current->link;
  }
  return true;
}

void board::setfirst()
{
     first = NULL;
}

void board::setlast()
{
     last = NULL;
}

void board::setmunitions()
{
ammo = 20;
hit = 0;
miss=0; 
}

int board::returnammo()
{ 
return ammo;     
}

int board::returnhits()
{
return hit;
}

int board::returnmiss()
{
return miss;
}

int board::returnhity()
{
return hity;
}