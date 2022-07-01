
int activitySelection(vector<int> start, vector<int> end, int n) {  
	vector<pair<int, int>> intervals(n);

	for(int i=0; i<n; i++) {
	    intervals[i].second = start[i];     // Putting the starting time as second.
	    intervals[i].first = end[i];        // Putting the finshing time as first.
	}

	sort(intervals.begin(), intervals.end());   	// Sort according to the finish time.

	int activitiesPerformed = 0, prevEnd = -1;

	for(int i=0; i<n; i++) {
	    if(intervals[i].second > prevEnd) {
		activitiesPerformed++;
		prevEnd = intervals[i].first;
	    }
	}

	return activitiesPerformed;
}
