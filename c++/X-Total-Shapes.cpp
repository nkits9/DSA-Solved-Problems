#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n, m;
void DFSVisit(vector<string> &A, int a, int b){
    A[a][b] = 'O';
    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};
    for(int k=0; k<4; k++) {
        int x = a + row[k];
        int y = b + col[k];
        if(x>=0 && x<n && y>=0 && y<m && A[x][y] == 'X') {
            DFSVisit(A, x, y);
        }
    }
}

int DFS(vector<string> &A) {
    int i,j,ans=0;
	for(i=0;i<A.size();i++){
		for(j=0;j<A[i].length();j++){
			if(A[i][j]=='X'){
				ans++;
				DFSVisit(A, i, j);
			}
		}
	}
	return ans;
}

int main() {
    IOS;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<string> A;
		for(int i=0;i<n;i++){
			string S;
			cin>>S;
			A.push_back(S);
		}
		cout<<DFS(A)<<endl;
	}
}