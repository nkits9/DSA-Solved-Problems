class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int count = 0, ans = -1, i = 0, j = 0;
        unordered_map<char, int> mp;
        
        while(j < s.size()) {
            if(mp[s[j]] == 0)   count++;
            mp[s[j]]++;
            
            if(count == k)  ans = max(ans, j-i+1);

            while(i <= j && count > k) {
                mp[s[i]]--;
                if(mp[s[i]] == 0)   count--;
                i++;
            }

            j++;
        }
        return ans;
    }
};
