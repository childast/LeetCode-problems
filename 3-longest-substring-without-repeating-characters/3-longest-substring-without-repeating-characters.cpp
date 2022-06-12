class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> existantChars;
        int p1 = 0, p2 = 0;
        int ans = 0;
        while(p2 < s.size()){
            if(!existantChars.count(s[p2])){
                existantChars.insert(s[p2]);
                p2++;
                ans = max(ans, (int)existantChars.size());
            }else{
                existantChars.erase(s[p1]);
                p1++;
            }
        }
        return ans;
    }
};