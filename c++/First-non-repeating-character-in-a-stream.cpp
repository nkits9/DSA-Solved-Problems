#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    IOS;
    int t;  cin >> t;
    while(t--) {
    	int n;	cin >> n;
    	int count[26] = {0};
		
		int i=0, j = 0;
		char arr[n];
    	while(i < n) {
    		
    		cin >> arr[i];
       		count[int(arr[i])-'a']++;
    		
    		while(count[int(arr[j])-'a'] > 1 && j < i) {
				j++;
			}

			if(count[int(arr[j])-'a'] > 1) 
				cout << -1 << " ";
			else 
				cout << arr[j] << " "; 
			
    		i++;
    	}
       	cout << endl;
    }
}