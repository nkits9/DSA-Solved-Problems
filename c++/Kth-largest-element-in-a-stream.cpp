#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

class cmp {
	public:
		bool operator()(int &A,int &B) {
			return A > B;
		}
};

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
        int k, n;
        cin >> k >> n;
        priority_queue<int, vector<int>, cmp> pq;
        int x;
        for(int i=0; i<n; i++) {
            cin >> x;
            if(i < k-1) {
                pq.push(x);
                cout << -1 << " ";
            }
            else if(i == k-1) {
                pq.push(x);
                cout << pq.top() << " ";
            }
            else {
                if(x > pq.top()) {
                    pq.pop();
                    pq.push(x);
                }
                cout << pq.top() << " ";
            }
    	}  
        cout << endl;
	}
}