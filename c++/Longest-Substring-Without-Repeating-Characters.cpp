class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int minIdx = -1, ans = 0;
        unordered_map<char, int> mp;
        
        for(int i=0; i<s.size(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                minIdx = max(minIdx, mp[s[i]]);
            }
            mp[s[i]] = i;
            ans = max(ans, i - minIdx);
        }
        
        return ans;
    }
    
};
