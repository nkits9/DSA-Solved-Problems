class Solution {
public:    
    bool wordBreak(int i, string s, vector<string> &dict) {
        if(i>=s.size()) {   
            return true;
        }

        for(int j=i+1; j<s.size(); j++) {
            string word = split(i, j, s);
            for(int k=0; k<dict.size(); k++) {
                if(word.compare(dict[k]) == 0) {
                    if(wordBreak(j+1, s, dict)) return true;
                }
            }
        }

        return false;
    }
}