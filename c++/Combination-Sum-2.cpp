typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
  public:
    //Function to return a list of indexes denoting the required combinations whose sum is equal to given number.
    
    void findCombination(vector<int> &arr, int start, int n, int sum, vvi &result, vi curr) {
        if(sum < 0) {
            return;
        }
        if(sum == 0) {
            result.push_back(curr);
            return;
        }
        for(int i=start; i<n; i++) {
            if(i==start || arr[i]!=arr[i-1]) {
                curr.push_back(arr[i]);
                findCombination(arr, i+1, n, sum-arr[i], result, curr);
                curr.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int> &arr, int n, int target) {
        sort(arr.begin(), arr.end());
        vvi res; vi curr;
        findCombination(arr, 0, n, target, res, curr);
        return res;
    }
};
