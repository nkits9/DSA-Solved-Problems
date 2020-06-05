#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

long swapCount(char s[]) {
    vector<int> pos;
    int n = strlen(s);
    // Keep track of '['
    for(int i=0; i<n; i++) {
        if(s[i]=='[')   pos.push_back(i);
    }
    int p = 0; // To track position of next '[' in pos.
    int unbal = 0, ans = 0;
    for(int i=0; i<n; i++) {
        if(s[i]=='[') {
            unbal++;
            p++;
        } 
        else if( s[i]==']') {
            if(unbal > 0) {
                unbal--;
            } 
            else if(unbal==0) {
                ans += pos[p] - i;
                swap(s[i], s[pos[p]]);
                i++;
                p++;
            }
        }
    }
    return ans;
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        char s[n];
        for(int i=0; i<n; i++) {
            cin >> s[i];
        }
     
        cout << swapCount(s) << endl;
    }
}