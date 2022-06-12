class Solution {
public:
    string numberToWords100(int num){
        map<int, string> m;
        m[0] = "Zero";
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[30] = "Thirty";
        m[40] = "Forty";
        m[50] = "Fifty";
        m[60] = "Sixty";
        m[70] = "Seventy";
        m[80] = "Eighty";
        m[90] = "Ninety";
        if(!num) return m[0];
        int hundreds = num / 100;
        int tens = num % 100;
        int digits = (num % 100) > 20 ? num % 10 : 0;
        tens -= digits;
        string ans = "";
        string space = "";
        if(hundreds){
            ans += m[hundreds] + " Hundred";
            space = " ";
        }
        if(tens){
            ans += space + m[tens];
            space = " ";
        }
        if(digits){
            ans += space + m[digits];
        }
        return ans;
    }
    string numberToWords(int num) {
       
        vector<string> l = {"Thousand", "Million", "Billion"};
        string ans = "";
        string space = "";
        if(num / (1000 * 1000 * 1000)){
            ans += numberToWords100(num / (1000 * 1000 * 1000)) + ' ' + l[2];
            num %= (1000 * 1000 * 1000);
            space = " ";
        }
        if(num / (1000 * 1000)){
            ans += space + numberToWords100(num / (1000 * 1000)) + ' ' + l[1];
            num %= (1000 * 1000);
            space = " ";
        }
        if(num / (1000)){
            ans += space + numberToWords100(num / (1000)) + ' ' + l[0];
            num %= (1000);
            space = " ";
        }
        if(ans.size() && !num) return ans;
        ans += space + numberToWords100(num);
        return ans;
    }
};