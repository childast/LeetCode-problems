class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void bfs(vector<vector<int>>& grid, int x, int y){
        queue<pair<int, int>> q;
        q.push({x, y});
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            grid[curr.first][curr.second] = 1;
            for(int i = 0; i < 4; i++){
                int xx = curr.first + dx[i];
                int yy = curr.second + dy[i];
                if(isValid(xx, yy) && !grid[xx][yy]){
                    q.push({xx, yy});
                }
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n; i++){
            if(!grid[i][m - 1]){
                bfs(grid, i, m - 1);
            }
            if(!grid[i][0]){
                bfs(grid, i, 0);
            }
        }
        for(int i = 0; i < m; i++){
            if(!grid[0][i]){
                bfs(grid, 0, i);
            }
            if(!grid[n - 1][i]){
                bfs(grid, n - 1, i);
            }
        }
        int nbIslands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j]){
                    bfs(grid, i, j);
                    nbIslands++;
                }
            }
        }
        return nbIslands;
    }
};