#include "board.h"
#include "ship.h"

using namespace std;

class battleshipGame 
{   
friend istream& operator>>(istream&, battleshipGame&);
friend istream& getline(istream&, battleshipGame&);
friend ostream& operator<<(ostream&, const battleshipGame&);


public:
battleshipGame();//contructor
~battleshipGame();//destructor

void initialize(int);// initialize ships, ammo, hits, level, and board.
void theConsole();// ammo available and total number of hits
void thelist();//
int hits;// number of hits user got
int ammo;//number of ammo remaining
int hity;

private:
board theBoard;
ship Submarine;
ship Destroyer;
ship Carrier;
};
