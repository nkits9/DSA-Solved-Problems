#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    pii p[n];
	    for(int i=0; i<n; i++) cin >> p[i].second; // Putting the starting time as second.
	    for(int i=0; i<n; i++) cin >> p[i].first;  // Putting the finshing time as first.
	    
	    sort(p, p+n);   // Now if we sort, it will sort according to the finish time.
	    
	    int ans = 1, j = 0;
	    for(int i=1; i<n; i++) {
	        if(p[i].second >= p[j].first) {
	            ans++;
	            j = i;
	        }
	    }
	    cout << ans << endl;
	}
}