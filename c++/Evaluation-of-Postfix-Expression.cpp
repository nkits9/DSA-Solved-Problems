#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int evaluatePostfix(string s) {
	stack<char> stack;
	for(int i=0; i<s.size(); i++) {
		char c = s[i];
		if(isdigit(c)) {
	        stack.push(c - '0');
	    }
        else {
            int a = stack.top();	stack.pop();
            int b = stack.top();	stack.pop();
            
            switch(c) {
                case '+' :
                    stack.push(b+a);
                    break;
                    
                case '-' :
                    stack.push(b-a);
                    break;
                    
                case '*' :
                    stack.push(b*a);
                    break;
                    
                case '/' :
                    stack.push(b/a);
                    break;
            }
        }
	}
	int result = stack.top();	stack.pop();
	return result;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << evaluatePostfix(s) << endl;
	}
}