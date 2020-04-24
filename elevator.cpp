// elevator.cpp

#include <iostream>
#include "string"
using namespace std;

int main() {
	int numFloors, current, goal, up, down;
	cin >> numFloors >> current >> goal >> up >> down;
	int count = 0;  // number of pushes used
	string mssg = "use the stairs\n";

	if (current > goal) {
		while (current>goal && down!=0) {
			current -= down;
			count++;
		}
		while (current<goal && up!=0) {
			current += up;
			count++;
		}
	} else {
		while (current<goal && up!=0) {
			current += up;
			count++;
		}
		while (current>goal && down!=0) {
			current -= down;
			count++;
		}
	}

	if (current == goal) cout << count << endl;
	else cout << mssg;
	return 0;
}

