class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int map[26] = {0};
        int i=0, j=0, ans=-1, unique = 0;
        
        while(j < s.size()) {
            
            if(map[s[j] - 'a'] == 0)    unique++;
            map[s[j] - 'a'] ++;
            
            if(unique == k) {
                ans = max(ans, j-i+1 );
            }
            
            while(i<=j && unique > k) {
                map[s[i] - 'a']--;
                if(map[s[i] - 'a'] == 0)    unique--;
                i++;
            }
            
            j++;
        }

        return ans;
    }
};
