#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for(int i=0; i<n; i++)  cin >> arr[i];
        sort(arr, arr+n);
        int ans = 0, minCoins = INT_MAX, removedPile = 0;
        for(int i=0; i<n; i++) {
      		ans = 0;
            for(int j=n-1; j>=i; j--) {
                if(arr[j]-arr[i] <= k) 
                    break;
                else 
                    ans += arr[j]-arr[i]-k;
            }
            minCoins = min(minCoins, ans + removedPile);
            removedPile += arr[i];
        }
        cout << minCoins << endl;
	}
}