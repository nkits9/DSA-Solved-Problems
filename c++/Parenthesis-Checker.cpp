#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

bool isBalanced(string x) {
    stack<char> s;
    for(int i=0; i<x.size(); i++) {
        if(x[i] == '{' || x[i] == '[' || x[i] == '(') {
            s.push(x[i]);
        }
        if(s.empty()) {
            s.push(x[i]);
            continue;
        }
        
        if(x[i] == '}') {
            if(s.top() == '{') {
                s.pop();
            } else {
                s.push(x[i]);
            }
        }
        if(x[i] == ']') {
            if(s.top() == '[') {
                s.pop();
            } else {
                s.push(x[i]);
            }
        }
        if(x[i] == ')') {
            if(s.top() == '(') {
                s.pop();
            } else {
                s.push(x[i]);
            }
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}


int main() {
    IOS;
    int t; cin>>t;
    string str;
    while(t--){
        cin>>str;
        if(isBalanced(str))
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;
    }
}



//Similar Problems :
//https://practice.geeksforgeeks.org/problems/print-bracket-number/0