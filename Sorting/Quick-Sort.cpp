/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std;  
  
  
int partition (int arr[], int l, int r) {  
    int pivot = arr[r]; // pivot  
    int i = (l - 1); // Index of smaller element  
  
    for (int j = l; j <= r; j++) {    
        if (arr[j] <= pivot) {  
            i++; // increment index of smaller element  
            swap(arr[i], arr[j]);  
        }  
    }    
    return i;  
}  

void quickSort(int arr[], int l, int r) {  
    if (l < r) {  
        // pi is partitioning index, arr[p] is now at right place 
        int pi = partition(arr, l, r);  
  
        // Separately sort elements before partition and after partition  
        quickSort(arr, l, pi - 1);  
        quickSort(arr, pi + 1, r);  
    }  
}  

// Driver Code 
int main() {  
    int arr[] = {9, 4, 6, 3, 7, 1, 2, 11, 5, -1, 100, 45, 3, 4};  
    int n = sizeof(arr) / sizeof(arr[0]); 

    quickSort(arr, 0, n - 1); 

    cout << "Sorted array: \n";  
    for(int i=0; i<n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;  
}  
  