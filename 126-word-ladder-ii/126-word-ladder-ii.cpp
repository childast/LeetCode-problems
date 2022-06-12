class Solution {
public:
    bool isNextStep(string word1, string word2){
        int cnt = 0;
        
        for(int i = 0; i < word1.size(); i++){
            if(word1[i] != word2[i])
                cnt++;
        }
        
        return cnt == 1;
    }
    int maxLevel = -1;
    map<string, vector<string>> buildGraph(string beginWord, string endWord, vector<string>& wordList){
        map<string, vector<string>> graph;
        queue<string> q;
        map<string, int> level;
        q.push(beginWord);
        level[beginWord] = 1;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(int i = 0; i < wordList.size(); i++){
                if(isNextStep(curr, wordList[i]) && (!level.count(wordList[i]) || level[wordList[i]] > level[curr])){
                    graph[curr].push_back(wordList[i]);
                    if(!level.count(wordList[i])){
                        q.push(wordList[i]);   
                    }
                    level[wordList[i]] = level[curr] + 1;
                }
            }
        }
        
        if(level.count(endWord)){
            maxLevel = level[endWord];
        }
        return graph;
    }
    
    vector<vector<string>> validLadders;
    
    void dfs(string curr, vector<string> validLadder, string endWord, map<string, vector<string>>& graph){
        if(curr == endWord){
            validLadders.push_back(validLadder);
            return;
        }   
        if(validLadder.size() == maxLevel)
            return;
        for(auto word: graph[curr]){
            validLadder.push_back(word);
            dfs(word, validLadder, endWord, graph);
            validLadder.pop_back();
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> graph = buildGraph(beginWord, endWord, wordList);
        if(maxLevel == -1)
            return validLadders;
        vector<string> validLadder;
        validLadder.push_back(beginWord);
        dfs(beginWord, validLadder, endWord, graph);
        return validLadders;
    }
};