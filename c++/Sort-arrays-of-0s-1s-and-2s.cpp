class Solution {
public:
    void sortColors(vector<int>& arr) {
        int lo = 0, mid = 0, hi = arr.size()-1;
        
        while(mid <= hi) {
            if(arr[mid] == 0) {
                swap(arr[mid], arr[lo]);
                mid++;
                lo++;
            }
            else if(arr[mid] == 1) {
                mid++;
            }
            else if(arr[mid] == 2) {
                swap(arr[mid], arr[hi]);
                hi--;
            }
        }
    } 
};

