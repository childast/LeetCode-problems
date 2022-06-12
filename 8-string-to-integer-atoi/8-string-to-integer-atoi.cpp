class Solution {
public:
    long long max(long long a, long long b){
        if(a > b) return a;
        return b;
    }
    long long min(long long a, long long b){
        if(a > b) return b;
        return a;
    }
    int myAtoi(string s) {
        long long ans = 0;
        bool isNegative = false;
        bool test = false;
        for(auto r : s){
            if(r == ' ' && !test) continue;
            if(r == '+' && ans == 0 && !test){
                test = true;
                continue;
            } 
            if(r == '-' && ans == 0 && !test){
                isNegative = true; 
                test = true;
                continue;
            } 
            if(!isdigit(r)){
                if(ans){
                    if(isNegative){
                        return max(-ans, -2147483648);
                    }else{
                        return min(ans, 2147483647);
                    }
                }else{
                    return ans;
                }
            }
            test = true;
            ans *= 10;
            ans += (r - '0');
            if(ans > 2147483647){
                if(isNegative){
                    return max(-ans, -2147483648);
                }else{
                    return min(ans, 2147483647);
                }
            }
        }
        if(ans){
            if(isNegative){
                return max(-ans, -2147483648);
            }else{
                return min(ans, 2147483647);
            }
        }else{
            return ans;
        }
    }
};