class Solution {
public:
    int romanToInt(string s) {
        map<char, int> conv;
        conv['I'] = 1;
        conv['V'] = 5;
        conv['X'] = 10;
        conv['L'] = 50;
        conv['C'] = 100;
        conv['D'] = 500;
        conv['M'] = 1000;
        int intNb = 0;
        char last =  ' ';
        for(int i = 0; i < s.size(); i++){
            if(conv.count(last) && conv[s[i]] > conv[last]){
                intNb -= 2 * conv[last];
            }
            intNb += conv[s[i]];
            last = s[i];
        }
        return intNb;
    }
};