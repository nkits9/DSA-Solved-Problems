class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> m;
        int count = 0, start = 0, minLen = INT_MAX;

        for(int i=0; i<t.size(); i++) {
            if(m[t[i]] == 0)    count++;
            m[t[i]]++;
        }

        int i=0;
        for(int j=0; j<s.size(); j++) {
            if(m.find(s[j]) != m.end()) {
                m[s[j]]--;
                if(m[s[j]] == 0) {
                    count--;
                }
            }
            if(count == 0) {

                while(i <= j) {
                    if(m.find(s[i]) == m.end()) {
                        i++;
                    }
                    else if(m[s[i]] < 0) {
                        m[s[i]]++;
                        i++;
                    }
                    else {
                        break;
                    }
                }

                if(j-i+1 < minLen) {
                    start = i;
                    minLen = j-i+1;
                }
            }
        }
        
        if(minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};