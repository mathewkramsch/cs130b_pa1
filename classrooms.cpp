// classrooms.cpp

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "string"
using namespace std;

bool compare_finishing(pair<int,int> a, pair<int,int> b) { return a.second<b.second; }

int main() {
	// VARIABLES FOR GETTING INPUT
	int numActivities, numClassrooms;
	vector<pair<int,int>> activities;  // vector to hold pairs of each activity start/end time
	pair<int,int> p (0,0);  // pair of start/end times
	int activityStart, activityEnd;  // each activity's start/end time

	// GETTING INPUT
	cin >> numActivities >> numClassrooms;
	for (int i=0; i<numActivities; i++) { 
		cin >> activityStart >> activityEnd;
		p = make_pair(activityStart, activityEnd);
		activities.push_back(p);
	}

	// CALCULATING MAX # ACTIVITIES TO BE HELD
	int count;  // count of number activities to be held (maximize this)
	pair<int,int> last (-1,-1);  // last activity to be scheduled
	int used = 0;  // number of classrooms used
	if (numActivities == numClassrooms) count = numActivities;
	else {
		sort(activities.begin(), activities.end(), compare_finishing);
			// sort by finishing time
		// iterate thru activities, schedule earlier elements first (unless conflict)
		for (int i=0; i<numClassrooms; i++) {  // do this for each classroom
			last = activities[0];
			activities.erase(activities.begin());
			count++;
			for (int i=1; i<numActivities; i++) {
				if (activities[i].first > last.second) {  // if != conflict w/ last scheduled activity
					last = activities[i];
					activities.erase(activities.begin()+i);
					count++;
				}
			}
		}
	}

	cout << count << endl;
	return 0;
}
