class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> count;
        for(auto c: s){
            count[c]++;
        }
        int ans = 0;
        int currMax = -1;
        vector<int> v;
        for(auto r: count){
            v.push_back(r.second);
        }
        sort(v.rbegin(), v.rend());
        for(auto r: v){
            if(currMax != -1 && currMax < r){
                ans += (r - currMax);
                currMax--;
            }else{
                currMax = r - 1;
            }
            currMax = max(currMax, 0);
        }
        return ans;
    }
};