#include <iostream>
#include <set>
using namespace std;

/*
    short function to check if an entry has already been chosen by the user using the STL; I would have to adapt this into a function
    and probably make a type analagous to Point2D for the coordinate system
*/

int main()
{
    set <int> guesses; // create set to store previous guesses
    int c;

    while (true)
    {
        cout << "enter integer: ";
        cin >> c;

        if(guesses.count(c) == 0) // if the input value is not already in the set, add it
            guesses.insert(c);

        else if (guesses.count(c) != 0) // if the input value has already been entered, ignore it
            cout << "already guessed" << endl;
    }

}