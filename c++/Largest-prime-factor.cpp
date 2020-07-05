#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    int ans = 1;
	    for(int i=2; i<=sqrt(n); i++) {
	        if(n%i==0) {
	            while(n%i==0) {
	                n = n/i;
	            }
	            ans = max(ans,i);
	        }
	    }
	    if(n>1) {
	        cout << n << endl;
	    } else {
	        cout << ans << endl;
	    }
	}
}
