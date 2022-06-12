class Solution {
public:
    int n, m;
    vector<vector<char>> Board;
    set<pair<int, int>> visited;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(int x, int y){
        visited.insert(make_pair(x, y));
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(isValid(xx, yy) && Board[xx][yy] == 'O' && !visited.count(make_pair(xx, yy))){
                dfs(xx, yy);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        Board = board;
        for(int i = 0; i < n; i++){
            if(board[i][m - 1] == 'O' && !visited.count(make_pair(i, m - 1))){
                dfs(i, m - 1);
            }
            if(board[i][0] == 'O' && !visited.count(make_pair(i, 0))){
                dfs(i, 0);
            }
        }
        for(int i = 0; i < m; i++){
            if(board[n - 1][i] == 'O' && !visited.count(make_pair(n - 1, i))){
                dfs(n - 1, i);
            }
            if(board[0][i] == 'O' && !visited.count(make_pair(0, i))){
                dfs(0, i);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !visited.count(make_pair(i, j)))
                    board[i][j] = 'X';
            }
        }
    }
};