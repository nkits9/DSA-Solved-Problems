#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;

void floydWarshall(int &n, vvi &d) {
    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main() {
	IOS;
	int t; 
	cin >> t;
	while(t--) {
        int n;
        cin >> n;
        vvi d(n, vi(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> d[i][j];
            }
        }
        
        floydWarshall(n, d);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(d[i][j] >= INF)
                    cout << "INF ";
                else
                    cout << d[i][j] << " ";
            }
            cout << endl;
        }
        
	}
}