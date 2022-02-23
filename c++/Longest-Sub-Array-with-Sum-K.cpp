int lenOfLongSubarr(int a[],  int n, int k) { 
    int sum = 0;
    int max_len = 0;
    unordered_map<int, int> umap;
    
    for(int i=0; i<n; i++) {
        sum += a[i];
        
        if(sum == k)
            max_len = i+1;
            
        if(umap.find(sum) == umap.end()) 
            umap[sum] = i;
            
        if(umap.find(sum-k) != umap.end())
            max_len = max(max_len, i - umap[sum-k]);

    }
    
    return max_len;
} 