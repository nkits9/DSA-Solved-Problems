class cmp {
public:
    bool operator()(int &A,int &B) {
        return A > B;
    }
};

vector<int> kthLargest(int k, int arr[], int n) {
    vector<int> res;
    priority_queue<int, vector<int>, cmp> pq;

    for(int i=0; i<n; i++) {
        if(i < k-1) {
            pq.push(arr[i]);
            res.push_back(-1);
        }
        else if(i == k-1) {
            pq.push(arr[i]);
            res.push_back(pq.top());
        }
        else {
            if(arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
            res.push_back(pq.top());
        }
    }

    return res;
}
