class Solution{
  public:
   int longestKSubstr(string s, int k) {
        int unique = 0, ans = -1, i = 0, j = 0;
        unordered_map<char, int> mp;
        
        while(j < s.size()) {
            if(mp[s[j]] == 0)   unique++;
            mp[s[j]]++;
            
            if(unique == k)  ans = max(ans, j-i+1);

            while(i <= j && unique > k) {
                mp[s[i]]--;
                if(mp[s[i]] == 0)   unique--;
                i++;
            }

            j++;
        }

        return ans;
    }
};
