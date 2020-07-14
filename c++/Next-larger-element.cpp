#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long

int main() {
    IOS;
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll arr[n], res[n];
        for(ll i=0; i<n; i++)  cin >> arr[i];
        
        stack<ll> s; 
        for(ll i=0; i<n; i++) {
            while(!s.empty() && arr[i] > arr[s.top()]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            if(s.empty() || arr[i] <= arr[s.top()]) {
                s.push(i);
            }
        }
        while(!s.empty()) {
            res[s.top()] = -1;
            s.pop();
        }
        
        for(ll i=0; i<n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}