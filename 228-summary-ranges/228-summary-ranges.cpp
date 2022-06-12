class Solution {
public:
    string range(int a, int b){
        if(a == b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int idx = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] + 1 != nums[i]){
                ans.push_back(range(nums[idx], nums[i - 1]));
                idx = i;
            }
        }
        if(nums.size())
        ans.push_back(range(nums[idx], nums[nums.size() - 1]));
        return ans;
    }
};