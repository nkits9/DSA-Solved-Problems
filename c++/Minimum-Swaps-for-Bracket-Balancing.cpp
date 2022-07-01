int minimumNumberOfSwaps(string s) {
    int close = 0, open = 0, unbal = 0, swaps = 0;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == '[') {
            open++;
            if(unbal > 0) {
                swaps += unbal;
                // swap(s[i], s[i-unbal]);
            }
        }
        else {
            close++;
        }
        unbal = close - open;
    }

    // cout << s << endl;     (In the end string will be always like this - "[][][][]")
    return swaps;
}
