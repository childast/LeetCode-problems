class Solution {
public:
    int halfSum = 0;
    int n;
    vector<int> Nums;
    int dp[201][20001];
    
    bool findPartition(int idx, int sum){
        if(sum == halfSum)
            return true;
        
        if(idx == n)
            return false;
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        return dp[idx][sum] = (findPartition(idx + 1, sum) || findPartition(idx + 1, sum + Nums[idx]));
    }
    
    bool canPartition(vector<int>& nums) {
        Nums = nums;
        n = nums.size();
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++){
            halfSum += nums[i];
        }
        if(halfSum % 2)
            return false;
        
        halfSum /= 2;
        return findPartition(0, 0);
    }
};