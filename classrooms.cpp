// classrooms.cpp

#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include "string"
using namespace std;

bool compare_finishing(pair<int,int> a, pair<int,int> b) { 
	if (a.second==b.second) return a.first<b.first;
	return a.second<b.second; 
}

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
	multiset<int> earliest_ending;  // keeps track of earliest ending time of scheduled activities accross classrooms
		// add new activity to classroom w/ latest ending time
	int count=0;  // count of number activities to be held (maximize this)
	pair<int,int> last (-1,-1);  // last activity to be scheduled
	if (numActivities == numClassrooms) { count = numActivities; cout << count << endl; return 0; }

	// iterate thru activities, schedule earlier finishing elements first (unless conflict)
	sort(activities.begin(), activities.end(), compare_finishing);  // sort by finishing time
	for (int i=0; i<activities.size(); i++) {
		if (earliest_ending.size() < numClassrooms) {
			earliest_ending.insert(activities[i].second);
			count++;
		}
		else {  // if != conflict w/ earliest ending scheduled activity
			if (activities[i].first <= *(earliest_ending.begin())) continue;
			
			// it = the max ending time < activities[i]'s starting time
			auto it = --earliest_ending.lower_bound(activities[i].first);
			earliest_ending.erase(it);
			earliest_ending.insert(activities[i].second);
			count++;
		}
	}

	cout << count << endl;
	return 0;
}
