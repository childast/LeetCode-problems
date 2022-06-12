class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int allBitsOn = (1 << nums.size()) - 1;
        for(int i  = 0; i <= allBitsOn; i++){
            vector<int> curr;
            for(int j = 0; j < nums.size(); j++){
                if ((1 << j) & i){
                    curr.push_back(nums[j]);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};