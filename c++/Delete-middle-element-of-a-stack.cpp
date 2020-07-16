stack<int> deleteMid(stack<int>s, int size ,int curr) {
    if(curr==size/2) {
        s.pop();
        return s;
    }
    int t = s.top();    s.pop();
    s = deleteMid(s, size, curr+1);
    s.push(t);
    return s;
}