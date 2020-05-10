#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
        int edge = 0;
	    while(n > 1) {
	        if(n%3 == 0)    
	            n /= 3;
	        else    
	            n -= 1;
	        edge++;
	    }
	    cout << edge << endl;
	}
	return 0;
}