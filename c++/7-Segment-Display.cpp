#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    IOS;
    int value[] = {6, 2, 5, 5, 4, 5, 6, 3 ,7, 5};
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        long long segments = 0;
        for(int i=0; i<n; i++) {
            segments += value[s[i]-'0'];
        }
        int i=0;
        while(i<n) {
            int j=0;
            while(j<10) {
                int x = value[j];
                int l = (n-1) - i;
                if(segments-x >= 2*l && segments-x <= 7*l) {
                    segments -= x;
                    cout << j;
                    break;
                }
                j++;
            }
            i++;
        } 
        cout << endl;       
    }
}