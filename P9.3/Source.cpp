/*Die run group function - Collin Snider*/
/*A run is a sequence of adjacent repeated values. Using an array, write a program that generates a sequence of
20 random six-sided die tosses, determines whether or not a run is present and prints out this information, and
prints all the die values, marking the runs by including them in parentheses, as shown in this example run:
no run: 1 2 3 4 3 2 6 4 5 3 2 3 1 3 4 5 6 2 1 3
has run: 1 2 (5 5) 3 1 2 4 3 (2 2 2 2) 3 6 (5 5) 6 3 1*/

#include <iostream>
#include <random>
using namespace std;

int rollDie(void);
void displayRuns(int dieRolls[], int size)             //group runs in parenthesis
{
    for(int i = 0; i < size; i++) {
		if (dieRolls[i] == dieRolls[i + 1]) {          //if adjacent, add parenthesis
        cout << "(";
		while (dieRolls[i] == dieRolls[i + 1]) {       //if some are adjacent, keep going until they are not, then end the parenthesis
            cout << dieRolls[i] << " ";
            i++;
        }
        cout << dieRolls[i] << ") ";
    }
    else {
        cout << dieRolls[i] << " ";
	}
	}
    
}

int rollDie(void) {
    static random_device rd;                            //function to ouput reandom from 1-6, or 1 dice roll
    static mt19937 gen(rd());
    static uniform_int_distribution<int> dist(1, 6);
    return dist(gen);
}

int main() {    
	const int SIZE = 20;                                //constant for size of array
	int dieRolls[SIZE];                                 //array to hold die rolls
        
    for (int i = 0; i < 20; i++) {
        rollDie();
		dieRolls[i] = rollDie();                        //fill array with die rolls
    }

    cout << "Die rolls: ";
	displayRuns(dieRolls, SIZE);                        //display die rolls with runs in parenthesis
	return 0;

}