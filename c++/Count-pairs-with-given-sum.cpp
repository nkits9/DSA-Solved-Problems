#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int noOfPairs(int a[], int n, int k, int start, int numOfElements, int &count) {
    if(k == 0 && numOfElements == 2) {
        count++;
        // printf("i = %d\n", start);
        return count;
    }
    if(k < 0) {
        return count;
    }
    if(numOfElements > 2) {
        return count;
    }
    for(int i=start; i<n; i++) {
        k = k - a[i];
        noOfPairs(a, n, k, i+1, numOfElements+1, count);
        k = k + a[i];
    }
    return count;
}

int main() {
    IOS;
    int t; 
    cin >> t;
    while(t-- > 0) {
        int n, k; 
        cin >> n >> k;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int count = 0;
        cout << noOfPairs(a, n, k, 0, 0, count) << endl;
    }
}