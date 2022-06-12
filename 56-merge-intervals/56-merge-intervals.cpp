class Solution {
public:
    bool intersect(vector<int>& a, vector<int>& b){
        return max(a[0], b[0]) <= min(a[1], b[1]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intersect(curr, intervals[i])){
                curr[0] = min(curr[0], intervals[i][0]);
                curr[1] = max(curr[1], intervals[i][1]);
            }else{
                ans.push_back(curr);
                curr = intervals[i];
            }
        }
        ans.push_back(curr);
        return ans;
    }
};