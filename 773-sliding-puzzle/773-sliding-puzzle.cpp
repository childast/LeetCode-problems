class Solution {
public:
    set<vector<vector<int>>> visited;
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    pair<int, int> getZero(vector<vector<int>>& board){
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(!board[i][j]){
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
    
    bool isValid(int x, int y){
        return x >= 0 && x < 2 && y >= 0 && y < 3;
    }
    
    vector<vector<int>> swap(vector<vector<int>> board, pair<int, int> p1, pair<int, int> p2){
        int inter = board[p2.first][p2.second];
        board[p2.first][p2.second] = board[p1.first][p1.second];
        board[p1.first][p1.second] = inter;
        return board;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<vector<vector<int>>, int>> q;
        vector<vector<int>> ref = {
            {1, 2, 3},
            {4, 5, 0}
        };
        q.push({board, 0});
        while(!q.empty()){
            vector<vector<int>> curr = q.front().first;
            int nbSteps = q.front().second;
            q.pop();
            if(curr == ref)
                return nbSteps;
            
            visited.insert(curr);

            pair<int, int> zeroPos = getZero(curr);
            for(int i = 0; i < 4; i++){
                if(!isValid(zeroPos.first + dx[i], zeroPos.second + dy[i]))
                    continue;
                vector<vector<int>> newBoard = 
                    swap(curr, zeroPos, {zeroPos.first + dx[i], zeroPos.second + dy[i]});
                if(!visited.count(newBoard))
                    q.push({newBoard, nbSteps + 1});
            }
        }
        return -1;
    }
};