class Solution {
public:
    bool overlap(vector<int>& a, vector<int>& b){
        return !(b[0] > a[1] || b[1] < a[0]);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            return {newInterval};
        }
        vector<vector<int>> ansIntervals;
        bool isOverlap = false;
        for(int i = 0; i < intervals.size(); i++){
            if(overlap(intervals[i], newInterval)){
                isOverlap = true;
                int start = min(intervals[i][0], newInterval[0]);
                int end = max(intervals[i][1], newInterval[1]);
                while(i < intervals.size() && overlap(intervals[i], newInterval)){
                    start = min(start, intervals[i][0]);
                    end = max(end, intervals[i][1]);
                    i++;
                }
                i--;
                ansIntervals.push_back({start, end});
            }else{
                ansIntervals.push_back(intervals[i]);
            }
        }
        
        if(!isOverlap){
            ansIntervals.push_back(newInterval);
            sort(ansIntervals.begin(), ansIntervals.end());
        }
        
        return ansIntervals;
    }
};