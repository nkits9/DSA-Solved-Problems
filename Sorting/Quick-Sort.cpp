/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std;  
  

int partition (int arr[], int low, int high) {
   int pivot = arr[high];
   int i = low, j = low;

   while(j <= high) {
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;  // increment index of smaller element  
        }
        j++;
    }
    return i-1;
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
  
