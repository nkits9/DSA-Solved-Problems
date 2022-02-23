class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;

        for(int i=0; i<nums.size(); i++) {
            while(!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i); 
            
            if(q.front() <= i-k) {
                q.pop_front();
            }

            if(i+1 >= k) {
                res.push_back(nums[q.front()]);
            }
        }

        return res;
    }
};