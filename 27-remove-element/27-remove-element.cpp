class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int mid, l = 0, r = 1;
        if(nums.size() < 1) return 0;
        int ans = nums.size();
        while(l < nums.size() && l < r){
            if(nums[l] == val){
                while(r < nums.size() && nums[r] == val) r++;
                if(r == nums.size()) return l;
                nums[l] = nums[r];
                nums[r] = val;
                r++;
            }
            l++;
            if(r == l) r++;
        }
        return l;
    }
};