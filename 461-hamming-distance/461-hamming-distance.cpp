class Solution {
public:
    int getBit(int x, int idx){
        if(((long long)1 << idx) & x) return 1;
        return 0;
    }
    int hammingDistance(long long x, long long y) {
        long long idx = 0, ans = 0;
        while(idx < 32 && ((long long)1 << idx) <= x || ((long long)1 << idx) <= y){
            if(getBit(x, idx) != getBit(y, idx)) ans++;
            idx++;
        }
        return ans;
    }
};