/* C++ implementation of QuickSort */
#include <bits/stdc++.h> 
using namespace std;  
  
// A utility function to swap two elements  
void swap(int* a, int* b) {  
    int t = *a;  
    *a = *b;  
    *b = t;  
}   

/* This function takes last element as pivot, places the pivot element at its 
correct position in sorted array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right of pivot */
int partition (int arr[], int low, int high) {  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high; j++) {    
        if (arr[j] <= pivot) {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }    
    return i;  
}  

void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        // pi is partitioning index, arr[p] is now at right place 
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
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
  