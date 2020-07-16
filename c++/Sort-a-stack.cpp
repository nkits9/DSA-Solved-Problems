void sortedInsert(stack<int> &s, int x) {
    if(s.empty() || x>s.top()) {
		s.push(x);
		return;
	}
	int temp = s.top();
	s.pop();
	sortedInsert(s,x);
	s.push(temp);
}

void SortedStack :: sort() {
    if(s.empty())   return;
		
	int x = s.top();
	s.pop();
	sort();
	sortedInsert(s,x);
}