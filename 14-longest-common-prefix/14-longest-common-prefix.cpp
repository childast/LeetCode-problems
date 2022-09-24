class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        string prefix = "";
        while(idx < strs[0].size()){
            char c = strs[0][idx];
            for(int i = 1; i < strs.size(); i++){
                if(idx >= strs[i].size() || strs[i][idx] != c){
                    return prefix;
                }
            }
            prefix += c;
            idx++;
        }
        return prefix;
    }
};