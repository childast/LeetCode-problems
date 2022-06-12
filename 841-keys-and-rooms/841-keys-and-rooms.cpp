class Solution {
public:
    unordered_set<int> visited;
    void DFS(int node, vector<vector<int>>& graph){
        visited.insert(node);
        for(int i = 0; i < graph[node].size(); i++){
            if(!visited.count(graph[node][i])){
                DFS(graph[node][i], graph);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        DFS(0, rooms);
        if(visited.size() < rooms.size()) return false;
        return true;
    }
};