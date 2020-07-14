class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};

int _stack :: getMin() {
    if(s.empty())   
        return -1;
    return minEle;
}

int _stack ::pop() {
    if(s.empty()) 
        return -1;
    int curr = s.top();
    s.pop();
    if(curr >= minEle) {
        return curr;
    } 
    else {
        int x = minEle;
        minEle = 2*minEle-curr;
        return x;
    }
}

void _stack::push(int curr) {
   if(s.empty()) {
       minEle = curr;
       s.push(curr);
   }
   else if(curr >= minEle) {
       s.push(curr);
   }
   else {
       s.push(2*curr - minEle);
       minEle = curr;
   }
}