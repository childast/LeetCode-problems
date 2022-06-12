class Solution {
public:
    unordered_map<long long, double> mem;
    double myPow(double x, long long n) {
        if(!n) return 1;
        if(n < 0) return 1.0 / myPow(x, -n);
        if(n == 1) return x;
        if(mem.count(n)) return mem[n];
        if(n % 2) return mem[n] = (myPow(x, n / 2) * myPow(x, n / 2) * x);
        return mem[n] = (myPow(x, n / 2) * myPow(x, n / 2));
    }
};