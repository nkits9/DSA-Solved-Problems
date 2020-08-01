#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n, x; 
	    cin >> n;

	    priority_queue<int, vector<int>, greater<int>> pq;
	    for(int i=0; i<n; i++) {
	        cin >> x;
	        pq.push(x);
	    }
        
	    long long int a, b, cost = 0;
	    while(pq.size() > 1) {
	        a = pq.top();   pq.pop();
	        b = pq.top();   pq.pop();
	        cost += a+b;
	        if(pq.empty())  break;
	        pq.push(a+b);
	    }
	    
	    if(!pq.empty()) {
	        cost += pq.top();
	    }
	    
	    cout << cost << endl;
	}
}