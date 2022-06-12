class Solution {
public:
    vector<vector<int>> allPermutations;
    vector<int> numbers;
    void GetPermutations(vector<int>& curr, int selected){
        if(curr.size() == numbers.size()){
            allPermutations.push_back(curr);
            return;
        }
        for(int i = 0; i < numbers.size(); i++){
            if(!(selected & (1 << i))){
                curr.push_back(numbers[i]);
                GetPermutations(curr, selected | (1 << i));
                curr.pop_back();
            }
        } 
    }
    vector<vector<int>> permute(vector<int>& nums) {
        numbers = nums;
        vector<int> v;
        GetPermutations(v, 0);
        return allPermutations;
    }
};