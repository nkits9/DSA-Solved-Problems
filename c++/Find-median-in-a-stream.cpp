#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int n;  cin >> n;
	
	priority_queue<int, vector<int>> minHeap;
	priority_queue<int, vector<int>, greater<int>> maxHeap;
	
	while(n--) {
	    int x;  cin >> x;
	    
	    maxHeap.push(x);
	    int e = maxHeap.top();
	    maxHeap.pop();
	    
	    minHeap.push(e);
	    
	    if(maxHeap.size() < minHeap.size()) {
	        e = minHeap.top();
	        minHeap.pop();
	        maxHeap.push(e);
	    }
	    
	    if(maxHeap.size() == minHeap.size()) 
	        cout << (maxHeap.top() + minHeap.top()) / 2 << endl;
	    else 
	        cout << maxHeap.top() << endl;
	    
	}
}