class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(char c: s) {
            mp[c]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            char c = it->first;
            int freq = it->second;
            pq.push({freq, c});
        }
        
        string res = "";
        
        while(pq.size() > 1) {
            pair<int, char> p1 = pq.top();
            pq.pop();
            pair<int, char> p2 = pq.top();
            pq.pop();
       
            res += p1.second;
            res += p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first > 0) {
                pq.push(p1);
            }
            if(p2.first > 0) {
                pq.push(p2);
            }
        }
        
        if(!pq.empty()) {
            if(pq.top().first > 1)     // single element present with freq > 1
                return "";
            else
                res += pq.top().second;
        }
        
        return res;
    }
};
