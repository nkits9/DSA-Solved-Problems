class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxWater = 0, i = 0, j = arr.size()-1;
        
        while(i<j) {
            maxWater = max(maxWater, (j-i)*min(arr[i], arr[j]));
            
            if(arr[i]<arr[j]) {
                i++;
            }  
            else if(arr[i]>arr[j]) {
                j--;
            }  
            else {
                if(arr[i+1]>arr[j])
                    i++;
                else 
                    j--;
            }
        }
        
        return maxWater;
    }
};