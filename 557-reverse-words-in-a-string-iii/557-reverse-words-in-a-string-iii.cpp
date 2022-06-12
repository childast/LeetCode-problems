class Solution {
public:
    string reverseWord(string s){
        string reversedString = "";
        for(int i = 0; i < s.size(); i++){
            reversedString += s[s.size() - 1 - i];
        }
        return reversedString;
    }
    
    string reverseWords(string s) {
        string aux = "";
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
            {
                ans += reverseWord(aux);
                ans += " ";
                aux = "";
            }
            else
            {
                aux += s[i];
            }
        }
        ans += reverseWord(aux);
        return ans;
    }
};