#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;

void findCombination(int *arr, int start, int n, int sum, vvi &result, vi curr) {
	if(sum < 0)	{
		return;
	}
	if(sum == 0) {
		result.push_back(curr);
		return;
	}
	for(int i=start; i<n; i++) {
		if(i==start || arr[i]!=arr[i-1]) {
			curr.push_back(arr[i]);
			findCombination(arr, i, n, sum-arr[i], result, curr);
			curr.pop_back();
		}
	}
	return;

}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    int arr[n];
	   	for(int i=0; i<n; i++) 
	    	cin >> arr[i];
	    sort(arr, arr+n);
	    int sum; cin >> sum;
	    vvi res; vi curr;
	    findCombination(arr, 0, n, sum, res, curr);
	    
	    if(res.empty()) {
	    	cout << "Empty" << endl;
	    }
	    else {
		    for(int i=0; i<res.size(); i++) {
		    	cout << "(";
		    	for(int j=0; j<res[i].size()-1; j++) {
		    		cout << res[i][j] << " ";
		    	}
		    	cout << res[i][res[i].size()-1] << ")";
		    }
		    cout << endl;
		}
	}
}