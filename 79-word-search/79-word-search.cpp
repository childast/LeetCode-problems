class Solution {
public:
    int n, m;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    bool dfs(int x, int y, int idx, string word, vector<vector<bool>> &vis, vector<vector<char>> &board){
        if(idx == word.size())
            return true;
        
        if(!isValid(x, y) || vis[x][y] || board[x][y] != word[idx])
            return false;
        
        vis[x][y] = true;
        bool ans = false;
        
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            ans |= dfs(xx, yy, idx + 1, word, vis, board);
        }
        
        vis[x][y] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i, j, 0, word, vis, board))
                    return true;
            }
        }
        
        return false;
    }
};