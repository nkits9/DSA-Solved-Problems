int maxLen(int arr[], int n) {
    int max_len = 0;
    int sum = 0;
    
    unordered_map<int, int> umap;
    umap[0] = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] == 1) 
            sum += 1;
        else
            sum -= 1;
        
        if(umap.find(sum) != umap.end())
            max_len = max(max_len, i - umap[sum]);
        else 
            umap[sum] = i;
    }
    return max_len;
}