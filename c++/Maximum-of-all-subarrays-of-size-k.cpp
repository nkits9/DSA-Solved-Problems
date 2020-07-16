#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

void maxSlidingWindow(int arr[], int n, int k) {
	deque<int> dq;
	for(int i=0; i<n; i++) {
		if(!dq.empty() && dq.front() <= i-k) {
			dq.pop_front();
		}
		while(!dq.empty() && arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
		if(i >= k-1) {
			cout << arr[dq.front()] << " ";
		}
	}
}
 
int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i=0; i<n; i++)	cin >> arr[i];	
		maxSlidingWindow(arr, n, k);
		cout << endl;
	}
}

/*
Similar Problems:
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k/0
*/