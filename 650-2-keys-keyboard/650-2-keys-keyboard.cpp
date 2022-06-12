class Solution {
public:
    int minSteps(int n) {
        if(n < 2) return 0;
        vector<int> exists;
        int curr = 2;
        int ans = 0;
        while(n > 1){
            if(n % curr == 0){
                n /= curr;
                ans += curr;
            }else{
                curr++;
            }
        }
        return ans + exists.size();
    }
};