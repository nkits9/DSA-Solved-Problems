#include <iostream>
using namespace std;
int count = 0;
int noOfPairs(int a[], int n, int k, int start, int numOfElements) {
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
        noOfPairs(a, n, k, i+1, numOfElements+1);
        k = k + a[i];
    }
    return count;
}

int main() {
    int t; 
    cin >> t;
    while(t-- > 0) {
        int n, k; 
        cin >> n >> k;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        count = 0;
        cout << noOfPairs(a, n, k, 0, 0) << endl;
    }
}