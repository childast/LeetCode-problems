class Solution {
public:
    vector<int> Coins;
    int n, Amount;
    int dp[301][5001];
    
    int getCombinations(int idx, int sum){
        if(sum == Amount)
            return 1;
        
        if(idx == n)
            return 0;
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int ans = 0;
        
        for(int i = idx; i < n; i++){
            if(sum + Coins[i] <= Amount)
                ans += getCombinations(i, sum + Coins[i]);
        }
        
        return dp[idx][sum] = ans;
    }
    
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        Coins = coins;
        Amount = amount;
        memset(dp, -1, sizeof dp);
        
        return getCombinations(0, 0);
    }
};