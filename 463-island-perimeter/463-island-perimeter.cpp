class Solution {
public:
    int n, m;
    vector<vector<int>> Grid;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool visited[101][101];
    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int dfs(int x, int y){
        visited[x][y] = 1;
        int ans = 0;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(isValid(xx, yy) && Grid[xx][yy] == 1){
                if(!visited[xx][yy])
                    ans += dfs(xx, yy);
            }else
                ans++;
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        Grid = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j])
                    return dfs(i, j);
            }
        }
        return 0;
    }
};