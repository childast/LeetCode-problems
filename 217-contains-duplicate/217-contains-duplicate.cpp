class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it : nums){
            if(s.count(it)){
                return true;
            }
            s.insert(it);
        }
        return false;
    }
};