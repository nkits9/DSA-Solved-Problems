#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t;
	cin >> t;
	while(t--) {
	    int n, sum;
	    cin >> n >> sum;
	    if(sum > 9*n || sum == 0) {
	        cout << -1 << endl;
	        continue;
	    }
	    string s = "";
	    while(n--) {
	        if(sum >= 9) {
	            s.append(to_string(9));
	            sum -= 9;
	        } else {
	            s.append(to_string(sum));
	            sum -= sum;
	        }
	    }
	    cout << s << endl;
	}
}