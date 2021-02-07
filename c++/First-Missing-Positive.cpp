// Method - 1 :

class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=0; i<n; i++) {
            while(arr[i] >= 1 && arr[i] <= n && arr[i]-1 != i && arr[i] != arr[arr[i]-1]) {
                swap(arr[i], arr[arr[i]-1]);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(arr[i] != i+1) 
                return i+1;
        }
        
        return n+1;
    }
};


// Method 2 :

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] <= 0)     nums[i] = n + 2;
        }
        
        for(int i=0; i<n; i++) {
            int idx = abs(nums[i]) - 1;
            if(idx < n) {
                nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
            }
        }
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                return i+1;
            }
        }
        return n+1;
    }
};

