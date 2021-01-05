vector <long long> nextLargerElement(long long arr[], int n){
    stack<long long> s;
    vector<long long> res;
    
    for(int i=n-1; i>=0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        
        if(s.empty()) {
            res.push_back(-1);
        } else {
            res.push_back(s.top());
        }
        
        s.push(arr[i]);
    }
    
    reverse(res.begin(), res.end());
    return res;
}