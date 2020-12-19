class Solution {
public:
    
    string split(int start, int end, string &s) {
        string word = "";
        for(int i=start; i<=end; i++) {
            word.push_back(s[i]);
        }
        return word;
    }
    
    bool checkWordBreak(int i, string &s, vector<string> &dict, vector<int> dp) {
        if(i>=s.size()) {   
            return true;
        }
        
        if(dp[i] != -1) {
            return dp[i]==1 ? true : false;
        }

        for(int j=i; j<s.size(); j++) {
            string word = split(i, j, s);
            for(int k=0; k<dict.size(); k++) {
                if(word.compare(dict[k]) == 0) {
                    dp[i] = checkWordBreak(j+1, s, dict, dp);
                    if(dp[i]==1)    return true;
                    
                }
            }
        }

        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) {
            return false;
        } else {
            vector<int> dp(s.size(), -1);
            return checkWordBreak(0, s, wordDict, dp);
        }
    }
    
};