#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct Job {
    int id; 
    int deadline;
    int profit;
};

bool comparator(Job a, Job b) {
    return a.profit > b.profit;
}

void printJobScheduling(Job *a, int n) {
    bool slot[n];
    for(int i=0; i<n; i++)  slot[i]=true;;
    
    sort(a, a+n, comparator);
    
    int task = 0, profit = 0;
    for(int i=0; i<n; i++) {
        for(int j=min(n, a[i].deadline)-1; j>=0; j--) {
            if(slot[j] != false) {
                profit += a[i].profit;
                task++;
                slot[j] = false;
                break;
            }
        }
    }
    cout << task << " " << profit << endl;
}

int main() {
	IOS;
	int t, n; 
	cin >> t;
	while(t--) {
	    cin >> n;
	    Job a[n];
	    for(int i=0; i<n; i++) {
	        cin >> a[i].id;
	        cin >> a[i].deadline;
	        cin >> a[i].profit; 
	    }
	    printJobScheduling(a, n);
	}
}