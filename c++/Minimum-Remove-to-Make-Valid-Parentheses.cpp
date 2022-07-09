class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(c == '(') {
                st.push(i);
            }
            else if(c == ')') {
                if(!st.empty() && s[st.top()] == '(') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }
        
        // -> Now stack contains indexes which should be removed.
        while(!st.empty()) {
            s[st.top()] = '#';              // we need to remove this char from string, for now mark it as #.
            st.pop();
        }
        
        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i] != '#') {              // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
