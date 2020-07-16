#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

//Function to return precedence of operators.
int prec(char c) {
    if(c == '^')    
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// The main function to convert infix expression to postfix expression.
void infixToPostfix(string s) {
    stack<char> st;
    int n = s.length();
    string res;
    for(int i = 0; i < n; i++) {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
            res+=s[i];

        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
            st.push('(');

        // If the scanned character is an ‘)’, pop and to output string from the stack until an ‘(‘ is encountered.
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                char c = st.top();
                st.pop();
                res += c;
            }
            if(st.top() == '(') {
                st.pop();
            }
        }

        //If an operator is scanned.
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                char c = st.top();
                st.pop();
                res += c;
            }
            st.push(s[i]);
        }

    }
    //Pop all the remaining elements from the stack
    while(!st.empty()) {
        char c = st.top();
        st.pop();
        res += c;
    }

    cout << res << endl;

}

//Driver program to test above functions
int main() {
    IOS;
    int t;  cin>>t;
    while(t--) {
        string exp;
        cin>>exp;
        infixToPostfix(exp);
    }
    return 0;
}
