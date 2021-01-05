class Solution {
public:
    
    string max(string &p1, string &p2, string &p3) {
        return p1.size() > p2.size() ? (p1.size() > p3.size() ? p1 : p3) : (p2.size() > p3.size() ? p2 : p3);
    }
    
    string maxLenPalin(int l, int r, string &s) {
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
    
    string longestPalindrome(string s) {
        string longestPalin = "";
        for(int i=0; i<s.size(); i++) {
            string palin1 = maxLenPalin(i, i, s);
            string palin2 = maxLenPalin(i, i+1, s);
            longestPalin = max(palin1, palin2, longestPalin);
        }
        return longestPalin;
    }
    
};