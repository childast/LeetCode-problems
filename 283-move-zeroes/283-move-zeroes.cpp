class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pointer = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                nums[pointer] = nums[i];
                if(i != pointer) nums[i] = 0;
                pointer++;
            }
        } 
    }
};