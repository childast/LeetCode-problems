class Solution {
public:
    vector<int> ans;
    int N, K;
    void generateNumbers(int curr, int len){
        if(len == N){
            ans.push_back(curr);
            return;
        }
        if(curr % 10 + K >= 0 && curr % 10 + K <= 9){
            generateNumbers(curr * 10 + (curr % 10 + K), len + 1);
        }
        if(curr % 10 - K >= 0 && curr % 10 - K <= 9 && curr % 10 + K != curr % 10 - K){
            generateNumbers(curr * 10 + (curr % 10 - K), len + 1);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        N = n;
        K = k;
        for(int i = 1; i <= 9; i++)
            generateNumbers(i, 1);
        return ans;
    }
};