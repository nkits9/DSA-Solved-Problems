class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)    return 0;
        
        bool isPrime[n+1], count = 0;
        memset(isPrime, true, sizeof(isPrime));
    	isPrime[0] = isPrime[1] = false;

        for(int i=2; i<n; i++) {
            if(isPrime[i]) {
                count++;
                for(int j = i*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return count;
    }
};