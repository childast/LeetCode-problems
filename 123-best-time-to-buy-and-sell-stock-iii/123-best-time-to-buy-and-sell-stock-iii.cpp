int dp[100001][4];
class Solution {
private:
    int n;
    vector<int> Prices;
    int trade(int idx, int transactions){
        if(idx == n || transactions == 4){
        return 0;
        }
        if(dp[idx][transactions] != -1)
            return dp[idx][transactions];
        if(transactions % 2){
            return dp[idx][transactions] = max(trade(idx + 1, transactions), Prices[idx] + trade(idx + 1, transactions + 1));
        }
         return dp[idx][transactions] = max(trade(idx + 1, transactions), max(0, - Prices[idx] + trade(idx + 1, transactions + 1)));
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        Prices = prices;
        n = Prices.size();
        return trade(0, 0);
    }
};