#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    IOS;
    int t;  cin >> t;
    while(t--) {
    	int n1, n2, n3;
    	cin >> n1 >> n2 >> n3;
    	map<int, int> m;
    	int x;
    	for(int i=0; i<n1; i++) {
    		cin >> x;
    		m[x] = 1;
    	}
    	for(int i=0; i<n2; i++) {
    		cin >> x;
    		if(m[x]==1) {
    			m[x] = 2;
    		}
    	}
    	for(int i=0; i<n3; i++) {
    		cin >> x;
    		if(m[x] == 2) {
    			m[x] = 3;
    		}
    	}
       	bool flag = false;
    	for(auto it = m.begin(); it != m.end(); it++) {
    		if(it->second == 3) {
    			cout << it->first << " ";
    			flag = true;
       		}
    	}
    	if(!flag) {
    		cout << -1;
    	}
    	cout << endl;	
    }
}
