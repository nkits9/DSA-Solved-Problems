class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result;
        unordered_map<char, int> map;
        
        for(int i=0; i<s.size(); i++) {
            map[s[i]] = i;
        }
        
        int start = 0, end = 0, i = 0;
        while(i < s.size()) {
            while(i <= end) {
                end = map[s[i]] > end ? map[s[i]] : end;
                i++;
            }
            result.push_back(i-start);
            start = i;
            end = i;
        }
        
        return result;
    }
};