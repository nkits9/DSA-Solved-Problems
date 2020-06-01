#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
        int x; cin>>x;
        int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        vector<int> ans;
        int i=9;
        while(i > 0 && x != 0) {
            if(fact[i] < x) {
                ans.push_back(i);
                x -= fact[i];
            } 
            else if(fact[i] == x) {
                ans.push_back(i);
                x = 0;
            }
            else {
                i--;
            }
        }
        for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
        cout << endl;
	}
}