class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        string s;
        for(auto it : strs){
            s = it;
            sort(s.begin(), s.end());
            if(!m.count(s)){
                m[s] = {it};
            }else{
                m[s].push_back(it);
            }
        }
        vector<vector<string>> ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};