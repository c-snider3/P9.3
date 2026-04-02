/*Die run group function - Collin Snider*/
//completed 

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
	bool hasRun = false;                                //boolean to determine if there is a run
    const int SIZE = 20;                                //constant for size of array
    int dieRolls[SIZE];                                 //array to hold die rolls

    for (int i = 0; i < 20; i++) {
        rollDie();
        dieRolls[i] = rollDie();                        //fill array with die rolls
    }


    for (int i = 0; i < SIZE - 1; i++) {                //check for adjacent values
        if (dieRolls[i] == dieRolls[i + 1]) {
            hasRun = true;
            break;
        }
    }

	if (hasRun)                                         //if there is a run, output has run, otherwise no run
        cout << "Has run: ";
    else
        cout << "No run: ";

	displayRuns(dieRolls, SIZE);                        //output with parenthesis around runs

}