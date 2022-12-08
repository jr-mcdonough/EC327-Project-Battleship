#include "Frigate.h"
#include "Ship.h"
#include "Cruiser.h"
#include <list>
const int rows = 10;
const int elements = 10;
class Console{
    protected:
        Ship* ship_ptr[10];
        list<Frigate*> frigate_ptr;
        //Frigate* frigate_ptr[10];
        Cruiser* cruiser_ptr[10];
        int maxships = 10;
        int matrix[rows][elements];
        int num_cruisers;
        int num_frigates=0;
        int num_ships=maxships;

    public:
        void Clear();
        void Show();
        void ShowFinal();
        int NumberOfShips();
        void SetCruisers();
        void SetFrigate();
        bool ShipAttack(int x,int y);
        int GetFrigates();
        Console(){
            int num_cruisers=0;
            int num_frigates=7;
            
        }
        ~Console(){
            for(int i=0;i<maxships;i++){
                delete ship_ptr[i];
            }
        }



};