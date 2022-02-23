class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {

        int currLen=0, maxLen=0, n=s.size();

        unordered_map<char, int> m;

        for(int i=0; i<n; i++) {
            currLen++;
            
            if(m.find(s[i]) != m.end()) {
                currLen = min(currLen, i - m[s[i]]);
            }
            
            m[s[i]] = i;
            maxLen = max(maxLen, currLen);
        }
        
        return maxLen;
    }
};