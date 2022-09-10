class Solution {
public:
    int dp[201][1001][2];
    const int OO = -1e9;
    int findMaxProfit(int k, int idx, vector<int>& prices, bool canSell){
        if(k == 0 || idx == prices.size()) return 0;
        if(dp[k][idx][canSell] != OO){
            return dp[k][idx][canSell];
        }
        int operation = canSell ? 1 : -1;
        return dp[k][idx][canSell] = max(findMaxProfit(k, idx + 1, prices, canSell),
                   findMaxProfit(k - 1, idx + 1, prices, !canSell) + operation * prices[idx]);
    }
    int maxProfit(int k, vector<int>& prices) {
        for(int i = 0; i <= 2 * k; i++){
            for(int j = 0; j <= prices.size(); j++){
                dp[i][j][0] = dp[i][j][1] = OO;
            }
        }
        return findMaxProfit(2 * k, 0, prices, 0);
    }
};