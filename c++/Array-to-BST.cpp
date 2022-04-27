class Solution {

public:
    void buildTree(vector<int>& nums, int start, int end, vector<int> & res) {
        if(start > end)     return;
        
        int mid = (start + end)/2;
        
        res.push_back(nums[mid]);
        
        buildTree(nums, start, mid-1, res);
        buildTree(nums, mid+1, end, res);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> res;
        buildTree(nums, 0, nums.size()-1, res);
        return res;
    }
}