class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size() == 1)
            return 1;
        
        vector<pair<int, int>> lowest, highest, mid;
        vector<int> candies(ratings.size());
        for(int i = 0; i < ratings.size(); i++){
            if(i == 0){
                if(ratings[i] <= ratings[i + 1]){
                    lowest.push_back(make_pair(ratings[i], i));
                }else{
                    mid.push_back(make_pair(ratings[i], i));
                }
            }else if(i == ratings.size() - 1){
                if(ratings[i - 1] < ratings[i]){
                    mid.push_back(make_pair(ratings[i], i));
                }else{
                    lowest.push_back(make_pair(ratings[i], i));
                }
            }else{
                int cnt = 0;
                if(ratings[i] > ratings[i + 1]){
                    cnt++;
                }
                if(ratings[i] > ratings[i - 1]){
                    cnt++;
                }
                if(cnt == 2){
                    highest.push_back(make_pair(ratings[i], i));
                }else if(cnt == 1){
                    mid.push_back(make_pair(ratings[i], i));
                }else{
                    lowest.push_back(make_pair(ratings[i], i));
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < lowest.size(); i++){
            candies[lowest[i].second] = 1;
            ans++;
        }
        
        sort(mid.begin(), mid.end());
        
        for(int i = 0; i < mid.size(); i++){
            if(mid[i].second == 0){
                ans += candies[1] + 1;
                candies[0] = candies[1] + 1;
            }else if(mid[i].second == ratings.size() - 1){
                ans += candies[ratings.size() - 2] + 1;
                candies[0] = candies[ratings.size() - 2] + 1;
            }else{
                int idx = mid[i].second;
                if(ratings[idx] > ratings[idx - 1]){
                    ans += candies[idx - 1] + 1;
                    candies[idx] = candies[idx - 1] + 1;
                }else{
                    ans += candies[idx + 1] + 1;
                    candies[idx] = candies[idx + 1] + 1;
                }
            }
        }
        for(int i = 0; i < candies.size(); i++){
            cout << candies[i] << " ";
        }
        cout<<endl;
        for(int i = 0; i < highest.size(); i++){
            int idx = highest[i].second;
            ans += (max(candies[idx - 1], candies[idx + 1]) + 1);
            candies[idx] = (max(candies[idx - 1], candies[idx + 1]) + 1);
        }
        
        for(int i = 0; i < candies.size(); i++){
            cout << candies[i] << " ";
        }
        
        return ans;
    }
};