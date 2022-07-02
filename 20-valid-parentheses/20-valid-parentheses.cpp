class Solution {
public:
    bool isOpen(char c){
        return c == '(' || c == '{' || c == '[';
    }
    bool isMatch(char a, char b){
        return 
            (a == '(' && b == ')')
            || (a == '{' && b == '}')
            || (a == '[' && b == ']');
    }
    bool isValid(string s) {
        stack<char> a;
        for(auto it : s){
            if(isOpen(it)){
                a.push(it);
            }else{
                if(a.empty() || !isMatch(a.top(), it)) return false;
                a.pop();
            }
        }
        if(a.empty())
        return true;
        return false;
    }
};