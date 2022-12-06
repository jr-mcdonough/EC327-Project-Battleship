#include "Frigate.h"
#include "Ship.h"
#include "Cruiser.h"
const int rows = 10;
const int elements = 10;
class Console{
    protected:
        Ship* ship_ptr[10];
        Frigate* frigate_ptr[10];
        Cruiser* cruiser_ptr[10];
        int maxships = 10;
        int matrix[rows][elements];
        int num_cruisers=0;
        int num_frigates=0;
        int num_ships;

    public:
        void Clear();
        void Show();
        void ShowFinal();
        int NumberOfShips();
        void SetCruisers();
        void SetFrigate();
        bool ShipAttack(int x,int y);



};