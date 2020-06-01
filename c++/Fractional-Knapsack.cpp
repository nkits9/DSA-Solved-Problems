#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct Item {
    double val;
    double weight;
};

int comparator(Item a, Item b) {
    return (a.val/a.weight) > (b.val/b.weight);
}

int main() {
    IOS;
    int t; cin >> t;
    while(t--) {
        int n; 
        int cap;
        double maxVal = 0.0;
        cin >> n >> cap;
        Item a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i].val >> a[i].weight;
        }
        sort(a, a+n, comparator);
        for(int i=0; i<n; i++) {
            if(cap >= a[i].weight) {
                maxVal += a[i].val;
                cap -= a[i].weight;
            } else {
                maxVal += (a[i].val/a[i].weight)*cap;
                cap = 0;
            }
        }
        printf("%.2f\n", maxVal);
    }
}