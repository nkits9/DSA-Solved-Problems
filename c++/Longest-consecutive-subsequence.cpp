#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	c_p_c();
	int t; cin >> t;
	while(t--) {
        int n, x;  cin >> n;
        vector<int> res;
        for(int i=0; i<n; i++) {
            cin >> x;
            int n = x;
            bool flag = true;
            while(n>0) {
                if(n%10==0 || n%10>3) {
                    flag = false;
                    break;
                }
                n = n/10;
            }
            if(flag)    res.push_back(x);    
        }
        
        if(res.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
	}
	
}