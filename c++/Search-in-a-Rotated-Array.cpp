#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

ll binarySearch(ll *a, ll l, ll r, ll k) {
    
    ll mid;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(k == a[mid]) {
            return mid;
        }
        if(k > a[mid]) {
            l = mid+1;
        } 
        else if (k < a[mid]) {
            r = mid-1;
        }
    } 
    return -1;
}

ll findPivot(int *a, ll n) {
    ll l = 0, r = n-1, mid;
    while(l <= r) {
        
    }
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll arr[n];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        ll k; cin >> k;

        ll pivot = findPivot(arr, n);
        if(pivot == -1) {
            cout << binarySearch(arr, 0, n-1, k) << endl;
        } else {
            if(k >= arr[0]) 
                cout << binarySearch(arr, 0, pivot, k) << endl;
            else
                cout << binarySearch(arr, pivot+1, n-1, k) << endl;
        }
    }
}