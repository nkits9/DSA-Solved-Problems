#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef pair<int, int> pii;

int find(pii pair, int n, pii *arr) {
    int i=0;
    while(i<n) {
        if(arr[i] == pair)  break;
        i++;
    }
    return i;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    pii arr[n], p[n];
	    for(int i=0; i<n; i++) cin >> arr[i].second;
	    for(int i=0; i<n; i++) cin >> arr[i].first;
	    for(int i=0; i<n; i++) p[i] = arr[i];
	    sort(p, p+n);
	    int j=0;
	    vector<int> ans;
	    ans.push_back(find(p[0], n, arr)+1);
	    for(int i=1; i<n; i++) {
	        if(p[i].second > p[j].first) {
	            ans.push_back(find(p[i], n, arr)+1);
	            j=i;
	        }
	    }
	    for(int i=0; i<ans.size(); i++)
	        cout << ans[i] << " ";
	    cout << endl;
	}
}