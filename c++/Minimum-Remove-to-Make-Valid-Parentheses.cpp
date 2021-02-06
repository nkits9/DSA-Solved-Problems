class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> stack;
        for(int i=0; i<s.size(); i++) {
            
            if(s[i] == '(') {
                stack.push({'(', i});
            }
            if(s[i] == ')') {
                if(!stack.empty() && stack.top().first == '(') {
                    stack.pop();
                } else {
                    stack.push({')', i});
                }
            }
        }
        
        while(!stack.empty()) {
            s[stack.top().second] = '-';
            stack.pop();
        }
        string result = "";
        for(int i=0; i<s.size(); i++) {
            if(s[i] != '-') {
                result += s[i];
            }
        }
        
        return result;
     }
};