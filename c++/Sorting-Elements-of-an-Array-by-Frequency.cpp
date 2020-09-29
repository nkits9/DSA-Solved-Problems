#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;

bool compare(pii a, pii b) {
	if(a.second == b.second) 
		return a.first < b.first;
	else
		return a.second > b.second;
}

int main() {
	IOS;
	int t;	cin >> t;
	while(t--) {
		int n, x; cin >> n;
		unordered_map<int, int> map;
		for(int i=0; i<n; i++) {
			cin >> x;
			map[x]++;
		}
		vector<pii> v;
		int i=0;
		for(auto it=map.begin(); it!=map.end(); it++) {
			if(it->second > 0 ) {
				v.push_back({it->first, it->second});
			}
			i++;
		}
		int count;
		sort(v.begin(), v.end(), compare);
		for(int i=0; i<v.size(); i++) {
			count = v[i].second;
			while(count--) {
				cout << v[i].first << " ";
			}
		}
		cout << endl;
	}
}