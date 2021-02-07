class Solution {
public:
    
    int partition (vector<int> &arr, int l, int r) {  
        int pivot = arr[r]; 
        int i = (l - 1); 

        for (int j = l; j <= r; j++) {    
            if (arr[j] <= pivot) {  
                i++;  
                swap(arr[i], arr[j]);  
            }  
        }    
        return i;  
    }  


    int quickSelect(vector<int> &arr, int l, int r, int k) {
        int pivot = partition(arr, l, r);

        if(k==pivot)    return arr[k];

        if(k > pivot)  {
            return quickSelect(arr, pivot+1, r, k);
        } else {
            return quickSelect(arr, l, pivot-1, k);
        }
    }
    
    
    int findKthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        return quickSelect(arr, 0, n-1, n-k);
    }
};