vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k) {
    vector<long long> res;
    queue<int> q;
    
    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            q.push(i);
        }
        
        if(i < k-1) {
            continue;
        }
        else if(i == k-1) {
            if(q.empty())
                res.push_back(0);
            else
                res.push_back(arr[q.front()]);
        }
        else {
            if(!q.empty() && q.front() <= i-k) {
                q.pop();
            }
            if(q.empty())
                res.push_back(0);
            else
                res.push_back(arr[q.front()]);
        }
        
    }

    return res;
}
