// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long mn = 0, mx = n;
        while(mn < mx){
            int mid = (mn + mx) / 2;
            bool isBad = isBadVersion(mid);
            if(isBad){
                mx = mid;
            }else{
                mn = mid + 1;
            }
        }
        return mn;
    }
};