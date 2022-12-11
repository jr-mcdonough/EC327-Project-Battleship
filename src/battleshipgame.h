#include "board.h"
#include "ship.h"

using namespace std;

class battleshipGame 
{   
friend istream& operator>>(istream&, battleshipGame&);// overloaded operator
friend istream& getline(istream&, battleshipGame&);
friend ostream& operator<<(ostream&, const battleshipGame&);//overloaded operator


public:
battleshipGame();//contructor
~battleshipGame();//destructor

void initialize(int);// initialize... cals various functions from board to initialize ship size, ammo, hits, level, and board.
void theConsole();// shows the ammo available and hits accomplished
void thelist();//linkedlist... adds each coordinate entered and whether hit or miss..
int hits;// number of hits user has accomplished
int ammo;//number of ammo or retrys user has remaining.
int hity;

private:
board theBoard;//composition the board.
ship Submarine;//composition ship... declare a submarine of type ship
ship Destroyer;// same as above, of type ship
ship Carrier;// same as above, of type ship
};