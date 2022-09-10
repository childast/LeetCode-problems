class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        vector<int> attacks;
        for(int i = 0; i < properties.size(); i++){
            attacks.push_back(properties[i][0]);
        }
        int ans = 0;
        map<int, int> m;
        int mx = properties[properties.size() - 1][1];
        for(int i = properties.size() - 1; i >= 0; i--){
            mx = max(mx, properties[i][1]);
            m[properties[i][0]] = max(m[properties[i][1]], mx);
        }
        for(int i = 0; i < properties.size(); i++){
            int idx = upper_bound(attacks.begin(), attacks.end(), properties[i][0]) - attacks.begin();
            if(idx < attacks.size() && m[attacks[idx]] > properties[i][1]){
                ans++;
            }
        }
        
        return ans;
    }
};