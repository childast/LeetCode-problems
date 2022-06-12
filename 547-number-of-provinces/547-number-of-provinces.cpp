class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[node] = true;
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size());
        int provinces = 0;
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                provinces++;
                dfs(i, isConnected, visited);
            }
        }
        return provinces;
    }
};