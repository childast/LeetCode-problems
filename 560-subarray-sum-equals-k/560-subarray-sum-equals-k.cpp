class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> sums;
        sums[0]++;
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans += sums[sum - k];
            sums[sum]++;
        }
        
        return ans;
    }
};