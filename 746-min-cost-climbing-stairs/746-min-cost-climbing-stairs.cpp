class Solution {
public:
    int dp[1001];
    int minCost(int index, vector<int>& cost){
        if(index >= cost.size())
            return 0;
        if(!dp[index])
            return dp[index] = (cost[index] + min(minCost(index + 1, cost), minCost(index + 2, cost)));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCost(0, cost), minCost(1, cost));
    }
};