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

ll findPivot(ll *a, ll l, ll r) {
    while(l <= r) {
        ll m = (l + r)/2; 
        if (m < r && a[m] > a[m+1]) 
            return m; 
          
        if (m > l && a[m] < a[m-1]) 
            return (m-1); 
          
        if (a[l] >= a[m]) 
            return findPivot(a, l, m-1); 
          
        return findPivot(a, m+1, r);
    }
    return -1;
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

        ll pivot = findPivot(arr, 0, n-1);
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