vector<int> countDistinct (int arr[], int n, int k) {
    vector<int> res;
    unordered_map<int, int> m;
    int count = 0;
    for(int i=0; i<k; i++) {
    	if(m[arr[i]] == 0)	count++;
    	
    	m[arr[i]]++;
    }
    res.push_back(count);

    for(int i=k; i<n; i++) {
    	m[arr[i-k]]--;
    	if(m[arr[i-k]] <= 0) {
    		m.erase(arr[i-k]);
    		count--;
    	}

    	if(m[arr[i]] == 0)	count++;
    	
    	m[arr[i]]++;
    	
    	res.push_back(count);
    }
    return res;
}
