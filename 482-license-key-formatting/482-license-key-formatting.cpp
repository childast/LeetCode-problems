class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        for(auto r : s){
            if(isalnum(r)) ans += r;
        }
        s = ans;
        ans = "";
        for(int i = 0; i < s.size() % k; i++){
            ans += toupper(s[i]);
        }
        string aux = "";
        for(int i = s.size() % k; i < s.size(); i++){
            if(aux.size() == k){
                if(ans.size()){
                    ans += '-';
                }
                ans += aux;
                aux = "";
            }
            aux += toupper(s[i]);
        }
        if(aux.size()){
            if(ans.size()) ans += '-';
            ans += (aux);
        }
        return ans;
    }
};