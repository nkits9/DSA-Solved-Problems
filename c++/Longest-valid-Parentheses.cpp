#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int longestValid(string str, int n) {
	stack<int> s;
	s.push(-1);
	int res = 0;
	for(int i=0; i<n; i++) {
		if(str[i] == '(') {
			s.push(i);
		}
		else if(str[i] == ')') {
			s.pop();
			if(s.empty()) {
				s.push(i);
			} else {
				res = max(res, i-s.top());
			}
		}
	}
	return res;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
		string str;
		cin >> str;
		int n = str.size();
		cout << longestValid(str, n) << endl;
	}
} 
