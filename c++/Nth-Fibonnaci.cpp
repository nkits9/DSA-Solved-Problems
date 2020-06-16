#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int fibo(int n) {
    int f[n+1];  	// array to store previous 2 numbers result.
    f[0] = 0;
    f[1] = 1;
    for(int i=2; i<=n; i++) {
        f[i] = (f[i-1] + f[i-2])%10; // only the last digit is stored.
    }
    return f[n]%10;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
	    int n; cin >> n;
	    cout << fibo(n) << endl;
	}
}