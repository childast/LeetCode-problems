class Solution {
public:
    long long countPrimes(long long n) {
        if(n < 2) return 0;
        bool isPrime[n];
        memset(isPrime, true, sizeof isPrime);
        isPrime[0] = 0;
        isPrime[1] = false;
        long long ans = 0;
        for(long long i = 2; i < n; i++){
            if(isPrime[i]){
                ans++;
                for(long long j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
};