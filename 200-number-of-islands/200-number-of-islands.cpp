class Solution {
public:
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(isValid(xx, yy) && grid[xx][yy] == '1' && !visited[xx][yy]){
                dfs(xx, yy, grid, visited);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        int islands = 0;
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size()));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    islands++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return islands;
    }
};