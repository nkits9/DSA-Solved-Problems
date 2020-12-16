class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maximum = 0, prev = 0;
        
        if(n==0)    return 0;
        
        for(int i=1; i<n; i++) {
            prev = max(prev + prices[i]-prices[i-1], 0);
            maximum = max(prev, maximum);
        }
        
        return maximum;
    }
};