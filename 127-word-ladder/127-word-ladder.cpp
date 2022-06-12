class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (int i = 0; i < wordList.size(); i++){
            wordSet.insert(wordList[i]);
        }
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push(make_pair(beginWord, 1));
        string currWord;
        int currRank;
        char store;
        while (!q.empty()){
            currWord = q.front().first;
            currRank = q.front().second;
            q.pop();
            if (currWord == endWord)
                return currRank;
            for (int i = 0; i < currWord.size(); i++){
                for (char c = 'a'; c <= 'z'; c++){
                    store = currWord[i];
                    currWord[i] = c;
                    if (!visited.count(currWord) && wordSet.count(currWord)){
                        visited.insert(currWord);
                        q.push(make_pair(currWord, currRank + 1));
                    }
                    currWord[i] = store;
                }
            }
        }
        return 0;
    }
};