class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int ans = arr[0], maxi = arr[0], mini = arr[0];

        for(int i=1; i<arr.size(); i++){
            int temp = maxi;
            maxi = max({maxi*arr[i], arr[i], mini*arr[i]});
            mini = min({temp*arr[i], arr[i], mini*arr[i]});
            ans = max(ans, maxi);
        }

        return ans;
    }
};