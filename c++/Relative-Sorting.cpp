#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		unordered_map<int, int> mp;
		int x;
		for(int i=0; i<n; i++) {
			cin >> x;
			mp[x]++;
		}
		for(int i=0; i<m; i++) {
			cin >> x;
			if(mp.find(x) != mp.end()) {
				int count = mp[x];
				mp.erase(x);
				while(count--) {
					cout << x << " ";
 				}
			}
		}
		vector<int> v;
		for(auto it = mp.begin(); it != mp.end(); it++) {
			int count = it->second;
			while(count--) {
				v.push_back(it->first);
			}
		}
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}