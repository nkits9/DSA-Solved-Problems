// Time Complexity: O(n)
// Space Complexity: O(1)


long maximumSumSubarray(int k, vector<int> &arr , int n){
    long sum = 0, ans = 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];

        if(i < k-1) {
            continue;
        }
        else if(i == k-1) {
            ans = max(sum, ans);
        }
        else {
            sum = sum - arr[i-k];
            ans = max(sum, ans);
        }
    }

    return ans;
}
