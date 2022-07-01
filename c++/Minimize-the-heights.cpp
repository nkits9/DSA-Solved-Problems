int getMinDiff(int arr[], int n, int k) {
	sort(arr, arr + n);
	int ans = arr[n-1] - arr[0]; // Maximum possible height difference

	int tmin, tmax;

	int big = arr[n-1] - k;
	int small = arr[0] + k;

	for(int i=1; i<n; i++) {
		if(arr[i] - k < 0)  continue;

		tmin = min(small, arr[i] - k);
		tmax = max(big, arr[i-1] + k);
		ans = min(ans, tmax - tmin); 
	}

	return ans;
}
