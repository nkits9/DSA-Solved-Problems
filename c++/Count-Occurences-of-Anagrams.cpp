int search(string pat, string txt) {
    unordered_map<char, int> mp;
    int n = txt.size(), k = pat.size(), count = 0, ans = 0, i = 0;
    
    for(int j=0; j<k; j++) {
        if(mp.find(pat[j]) == mp.end())   count++;
        mp[pat[j]]++;
    }
    
    for(i=0; i<n; i++) {

        if(mp.find(txt[i]) != mp.end()) {
            mp[txt[i]]--;
            if(mp[txt[i]] == 0) count--; 
        }
        
        if(i>=k && mp.find(txt[i-k]) != mp.end()) {
            if(mp[txt[i-k]] == 0)   count++;
            mp[txt[i-k]]++;
        }

        if(count == 0) {
            ans++;
        }

    }
    
    return ans;
}