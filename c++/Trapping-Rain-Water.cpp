// Method 1: Dynamic Programming 
// Time - O(n)
// Space - O(n)

class Solution {
public:
    int trap(vector<int> &height) {
        int totalWater = 0, n = height.size();
        if(n==0)    return 0;

        int left_max[n], right_max[n];
        left_max[0] = height[0], right_max[n-1] = height[n-1];

        for(int i=1; i<n; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }

        for(int i=n-2; i>=0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }

        for(int i=0; i<n; i++) {
            totalWater += max(min(left_max[i], right_max[i]) - height[i], 0);
        }

        return totalWater;
    }
};


// Method 2: Stack
// Time - O(n)
// Space - O(1)


