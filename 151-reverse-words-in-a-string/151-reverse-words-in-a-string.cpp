class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string aux = "";
        for(auto r : s){
            if(r != ' '){
                aux += r;
            }else{
                if(aux.size()){
                    ans.push_back(aux);
                    aux = "";
                }
            }
        }
        if(aux.size()){
            ans.push_back(aux);
        }
        reverse(ans.begin(), ans.end());
        string ansString = "";
        for(auto r : ans){
            if(ansString.size()){
                ansString += (' ' + r);
            }else{
                ansString += r;
            }
        }
        return ansString;
    }
};