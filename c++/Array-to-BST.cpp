#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"



void createBST(int arr[], int l, int r) {
    if(l > r)   return;
    
    int mid = (r-l)/2 + l;
    cout << arr[mid] << " ";

    createBST(arr, l, mid-1);
    createBST(arr, mid+1, r);
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    int arr[n];
	    for(int i=0; i<n; i++)  cin >> arr[i];
	    
        createBST(arr, 0, n-1);
        cout << endl;
	}
}