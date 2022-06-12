class Solution {
public:
    int parents[2001];
    vector<int> graph[2001];
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        set<int> allElements;
        for(int i = 0; i < numCourses; i++){
            allElements.insert(i);
        }
        for(int i = 0; i < prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            allElements.erase(a);
            parents[a]++;
            graph[b].push_back(a);
        }
        vector<int> ans;
        if(allElements.empty())
            return ans;
        queue<int> q;
        for(auto it: allElements){
            q.push(it);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int i = 0; i < graph[curr].size(); i++){
                parents[graph[curr][i]]--;
                if(parents[graph[curr][i]] == 0)
                    q.push(graph[curr][i]);
            }
        }
        if(ans.size() != numCourses)
            ans.clear();
        return ans;
    }
};