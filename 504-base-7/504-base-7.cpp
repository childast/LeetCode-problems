class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        if(num < 0) return "-" + convertToBase7(-num);
        
        string ans = "";
        while(num){
            ans += (char)('0' + num % 7);
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};