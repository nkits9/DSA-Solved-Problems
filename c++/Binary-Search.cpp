
/* Recursive Approach:
 Time Complexity : O(logn) 	
 Space Complexity : O(logn)
*/
int bin_search(int a[], int left, int right, int k) {
    
    if(left > right)    return -1;
    
    int mid = (left + right)/2 ;
    
    if(k == a[mid]) return mid;
    
    if(k > a[mid]) 
        return bin_search(a, mid+1, right, k);
    else
        return bin_search(a, left, mid-1, k);
         
}


/* Iterative Approach(Efficient):
 Time Complexity : O(logn) 	
 Space Complexity : O(1)
*/
int binarySearch(int arr[], int l, int r, int x) { 
    while (l <= r) { 
        int m = (l + r)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
    } 
    // if we reach here, then element was not present.
    return -1; 
} 
