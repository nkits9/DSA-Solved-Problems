class compare {
	public:
		bool operator()(pair<char, int> A, pair<char, int> B) {
			return A.second < B.second;
		}
};

int main() {
    IOS;
    c_p_c();
    int t;  cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	unordered_map<char, int> m;
    	for(int i=0; i<s.size(); i++) {
    		m[s[i]]++;
    	}
    	priority_queue<pair<char, int>, vector<pair<char, int>>, compare> pq;
    	for(auto it = m.begin(); it != m.end(); it++) {
    		pq.push({it->first, it->second});	
    	}
    	int ans = 1;
    	while(!pq.empty()) {
    		pair<char, int> x = pq.top();	pq.pop();

    		if(pq.empty()) {
    			if(x.second > 1)	ans = 0;   			
    			break;
    		}
    		
    		pair<char, int> y = pq.top(); 	pq.pop();

    		if(x.second > 1)
    			pq.push({x.first, x.second-1});
    		if(y.second > 1)
    			pq.push({y.first, y.second-1});
    	}
    	cout << ans << endl;
    }
}