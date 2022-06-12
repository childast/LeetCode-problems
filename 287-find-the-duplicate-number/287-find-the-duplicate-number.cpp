class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto r : nums){
            if(s.count(r)) return r;
            s.insert(r);
        }
        return 0;
    }
};