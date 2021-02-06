class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, lowestIdx = 0, count = 0;
        unordered_map<char, int> map;

        for(int i=0; i<s.size(); i++) {
            if(map.find(s[i]) != map.end() && map[s[i]] >= lowestIdx) {
                count = i - map[s[i]];
                lowestIdx = map[s[i]]+1;
            } else {
                count++;
            }
            map[s[i]] = i; 
            maxLen = max(count, maxLen);
        }

        return maxLen;
    }
};