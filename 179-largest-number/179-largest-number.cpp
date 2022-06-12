class Solution {
public:
    
  static  bool compare(string a, string b){
        return a + b < b + a;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto r: nums){
            v.push_back(to_string(r));
        }
         sort(v.begin(), v.end(), compare);
         string res = "";
         for(int i = v.size() - 1; i >= 0; i--){
            res += v[i];
         }
        if(res[0] == '0') return "0";
         return res;
    }
};