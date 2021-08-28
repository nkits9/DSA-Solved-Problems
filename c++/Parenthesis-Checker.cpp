bool isValid(string s) {
    stack<char> st;
    int i = 0;

    while(i < s.size()) {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
            st.push(s[i]);
        }

        if(s[i]==')') {
            if (st.empty() || st.top()!='(')
                return false;
            st.pop(); 
        }

        if(s[i]==']') {
            if (st.empty() || st.top()!='[')
                return false;
            st.pop(); 
        }

        if(s[i]=='}') {
            if (st.empty() || st.top()!='{')
                return false;
            st.pop(); 
        }

        i++;
    }

    if(!st.empty()) 
        return false;

    return true;
}
