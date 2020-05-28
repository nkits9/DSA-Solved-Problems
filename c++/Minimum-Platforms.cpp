#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
	IOS;
	int t, n;
	cin >> t;
	while(t--) {
    	cin >> n;
    	int arr[n], dep[n];
        for(int i=0; i<n; i++)  cin >> arr[i];
        for(int i=0; i<n; i++)  cin >> dep[i];
        
        // Main Code:
        sort(arr, arr+n);
        sort(dep, dep+n);
        int i=0, j=0, platform=0, occupied=0;
        while(i<n && j<n) {
            if(arr[i] <= dep[j]) {
                if(platform <= occupied)
                    platform++;
                occupied++;
                i++;
            }
            else {
                occupied--;
                j++;
            }
        }
        cout << platform << endl;
	}
}