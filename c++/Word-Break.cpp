class Solution {
public:
    
    bool checkWordBreak(int start, string s, unordered_set<string> &dict, vector<int> &dp) {
        if(start >= s.size()) {
            return true;
        }

        if(dp[start] != -1) {
            return dp[start];
        }

        for(int i=start+1; i<=s.size(); i++) {
            
            // break at i => [start, i) + [i, s.size())
            
            string word = s.substr(start, i-start);

            if(dict.find(word) != dict.end()) {
                dp[i] = checkWordBreak(i, s, dict, dp);
                if(dp[i])  return true;
            }

        }

        return false;
    }



    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0)   return false;
        
        vector<int> dp(s.size()+1, -1);
        unordered_set<string> dict;

        for(int i=0; i<wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }

        return checkWordBreak(0, s, dict, dp);
    }
    
};
