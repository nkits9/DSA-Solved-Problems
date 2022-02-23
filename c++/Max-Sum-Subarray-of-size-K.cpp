// Time Complexity: O(n)
// Space Complexity: O(1)


int maximumSumSubarray(int k, vector<int> &arr , int n) {
    
    int ans = 0, sum = 0;
    
    for(int i=0; i<k; i++) {
        sum += arr[i];
    }
    
    ans = max(sum, ans);
    

    for(int i=k; i<n; i++) {
        sum = sum + arr[i] - arr[i-k];
        ans = max(sum, ans);
    }
    
    return ans;
    
}
