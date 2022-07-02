class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num: nums) {
            set.insert(num);
        }
        
        int longestStreak = 0;
        
        for(int i=0; i<nums.size(); i++) {
            int curr = nums[i];
            int prev = curr - 1;
            
            // If prev doesn't exist in set then it is the starting element of consecutive sequence.
            if(set.find(prev) == set.end()) {
                int count = 0;
                while(set.find(curr) != set.end()) {
                    count++;
                    curr++;
                }
                longestStreak = max(count, longestStreak);   
            }
        }
        
        return longestStreak;
    }
};