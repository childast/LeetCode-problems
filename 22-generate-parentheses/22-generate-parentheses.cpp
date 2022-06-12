class Solution {
public:
    vector<string> ans;
    
    void formAllCombinations(int open, int close, string currentCombination){
        if(!open && !close){
            ans.push_back(currentCombination);
        }
        if(open) formAllCombinations(open - 1, close, currentCombination + '(');
        if(close > open) formAllCombinations(open, close - 1, currentCombination + ')');
    }
    
    vector<string> generateParenthesis(int n) {
        formAllCombinations(n, n, "");
        return ans;
    }
};