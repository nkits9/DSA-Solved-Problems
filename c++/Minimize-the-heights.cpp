#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int getMinDiff(int arr[], int n, int k) { 
    if (n == 1) 
       return 0; 
   
    sort(arr, arr+n);
    int ans = arr[n-1]-arr[0]; 
    
    int small = arr[0]+k; 
    int big = arr[n-1]-k; 

    if (small > big) 
       swap(small, big); 

    for (int i=1; i<n-1; i++) { 
        int sub = arr[i] - k; 
        int add = arr[i] + k; 
        if (sub >= small || add <= big) 
            continue;  
        if (big-sub <= add-small) 
            small = sub; 
        else
            big = add; 
    } 

    return  min(ans, big - small); 
} 
int main() {
	IOS;
	int t, k, n;
	cin >> t;
	while(t--) {
	    cin >> k >> n;
	    int arr[n];
	    for(int i=0; i<n; i++) cin >> arr[i];
	    
	    cout << getMinDiff(arr, n, k) << endl;
	}
}