#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n, x; 
	    long long k;
	    cin >> n >> k;
	    unordered_map<long long, bool> m;
	    for(int i=0; i<n; i++) {
	        cin >> x;
	        m[x] = true;
	    }
	    int i=1, numOfCoins = 0;
	    while(k > 0) {
	        if(!m[i]) {
	            k -= i;
	            if(k < 0)	break;
	            numOfCoins++;
	        }
	        i++;
	    }
	    cout << numOfCoins << endl;
	}
}