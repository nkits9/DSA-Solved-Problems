
// Method 1: Time = O(nlog(n) + n^2), Space = O(1)

int minSteps(int arr[], int n, int k) {
	sort(arr, arr+n);

	int ans = INT_MAX, removedPile = 0;

	for(int i=0; i<n; i++) {
	    int minCoins = 0;
	    for(int j=n-1; j>i; j--) {
			if(arr[j] - arr[i] <= k)    break;
			minCoins += (arr[j] - arr[i] - k);
	    }
	    ans = min(removedPile + minCoins, ans);
	    removedPile += arr[i];
	}

	return ans;
}


// Method 2(optimal): Time = O(nlog(n) + nlog(n)), Space = O(n)
// ** uper_bound time complexity: log2(last – first) + O(1) == log(n)

int minSteps(int arr[], int n, int k) {
	sort(arr, arr+n);

	int prefix[n];
	prefix[0] = arr[0];
	for(int i=1; i<n; i++) {
		prefix[i] = prefix[i-1] + arr[i];
	}

	int ans = INT_MAX, removedPile = 0;

	for(int i=0; i<n; i++) {
		int idx = upper_bound(arr+i, arr+n, arr[i]+k) - arr;

		int actualSum = prefix[n-1] - prefix[idx-1];
		int permissibleSum = (arr[i] + k) * (n - idx);

		if(i>0 && arr[i] != arr[i-1]) {
			removedPile = prefix[i-1];
		}

		ans = min(removedPile + (actualSum - permissibleSum), ans);
	}

	return ans;
}
