class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size() < p.size()) return res;
        vector<int> vs(26), vp(26);
        for(int i = 0; i < p.size(); i++){
            vs[s[i] - 'a']++;
          vp[p[i] - 'a']++;
        }
        int idx = 0;
        for(int index = 0; index + p.size() <= s.size(); index++){
            if(vp == vs) res.push_back(index);
          if(index + p.size() < s.size()){
            vs[s[index] - 'a']--;
            vs[s[index + p.size()] - 'a']++;
          }
        }
        return res;
    }
};