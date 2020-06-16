#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

/*  Main Idea: 
		->(A*B)%M = ((A%M)*(A%M))%M
	so,
		->(x^y)%z = (x^(y/2)%z * x^(y/2)%z)%z
*/

//Recursive Solution:
// find (x^y)%z.
int power (int x, int y, int z) {
    if(y==1)    
        return x%z;
    // divide powers into two halves.
    while(y >= 1) {
    	int p = power(x, y/2, z); // save the result of first half.
        if(y%2==0)
            return  (p*p)%z; // if y is even.
        else
            return  ((p*p)%z*(x)%z)%z; // if y is odd.
    }  
    return 0;
}

int main() {
	IOS;
	c_p_c();
	int t; cin >> t;
	while(t--) {
	    int a, b, c;
	    cin >> a >> b >> c;
	    cout << power(a, b, c) << endl;	    
	}
}