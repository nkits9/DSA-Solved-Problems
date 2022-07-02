int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr+n);
	sort(dep, dep+n);

	int i=0, j=0, platform=0, occupied=0;
	
	while(i<n && j<n) {
		if(arr[i] <= dep[j]) {
			if(platform <= occupied)
				platform++;
			occupied++;
			i++;
		}
		else {
			occupied--;
			j++;
		}
	}

	return platform;
}
