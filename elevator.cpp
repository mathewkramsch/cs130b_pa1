// elevator.cpp

#include <iostream>
#include "string"
using namespace std;

int main(int argc, char *argv[]) {
	int const numFloors = argv[1];  // total number of floors
	int current = argv[2];  // current floor
	int const goal = argv[3];  // floor to reach
	int const up = argv[4];  // number floors up when press UP
	int const down = argv[5];  // number floors down when press DOWN
	int count  = 0;  // number of pushes used
	string mssg = "use the stairs\n";

	if (current == goal) cout << mssg;
	else if (current > goal) {
		while (current > goal) {
			current -= down;
			count++;
		}
		if (current != goal) {  // then overshot, go one up
			// do some shit
		}
	} 
	else {
		while (current < goal) {
			current += up;
			count++;
		}
		if (current != goal) {
		}
	}

	cout << count << endl;
	return 0;
}

