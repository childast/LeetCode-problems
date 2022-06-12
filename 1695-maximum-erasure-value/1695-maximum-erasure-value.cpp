class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxScore = 0;
        int currScore = 0;
        int currIdx = 0;
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            while(s.count(nums[i])){
                s.erase(nums[currIdx]);
                currScore -= nums[currIdx];
                currIdx++;
            }
            s.insert(nums[i]);
            currScore += nums[i];
            maxScore = max(maxScore, currScore);
        }
        return maxScore;
    }
};