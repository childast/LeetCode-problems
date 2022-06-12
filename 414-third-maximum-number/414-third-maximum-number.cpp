class Solution {
public:
    bool isDiff(int x, int y, int z){
        return x != y && x != z && y != z;
    }
    int thirdMax(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.size() == 2) return max(nums[0], nums[1]);
        int cnt = 1;
        while(cnt < nums.size() && nums[cnt] == nums[0]){
            cnt++;
        }
        if(cnt == nums.size()) return nums[0];
        
        int n1 = max(nums[0], nums[cnt]);
        int n2 = min(nums[0], nums[cnt]);
        int ans;
        bool check = false;
        for(int i = cnt + 1; i < nums.size(); i++){
            if(isDiff(n1, n2, nums[i])){
                if(nums[i] > n1){
                    ans = n2;
                    n2 = n1;
                    n1 = nums[i];
                }else if(nums[i] > n2){
                    ans = n2;
                    n2 = nums[i];
                }else if(!check || ans < nums[i]){
                    ans = nums[i];
                }
                check = true;
            }
        }
        if(check) return ans;
        else return n1;
    }
};