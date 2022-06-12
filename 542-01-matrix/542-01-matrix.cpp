class Solution {
public:
    int isValid(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        int m = mat[0].size();
        int n = mat.size();
        for (int i = 0; i < n; i++){
            ans.push_back({});
            for (int j = 0; j < m; j++){
                if (!mat[i][j]){
                    ans[i].push_back(0);
                    q.push(make_pair(i, j));
                }else{
                    ans[i].push_back(-1);
                }
            }
        }
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (isValid(xx, yy, n, m) && ans[xx][yy] == -1){
                    ans[xx][yy] = ans[x][y] + 1;
                    q.push(make_pair(xx, yy));
                }
            }
        }
        return ans;
    }
};