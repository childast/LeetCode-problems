class TrieNode {
public:
    vector<TrieNode*> edges;
    bool isWord;
    TrieNode(){
        edges = vector<TrieNode*>(26, nullptr);
        isWord = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++){
            if(curr->edges[word[i] - 'a'] == nullptr){
                curr->edges[word[i] - 'a'] = new TrieNode();
            }
            curr = curr->edges[word[i] - 'a'];
        }
        curr->isWord = true;
    }
    
    bool searchWord(string& word, int idx, TrieNode* curr){
        if(curr == nullptr)
            return false;
        for(int i = idx; i < word.size(); i++){
            if(word[i] == '.'){
                for(auto it: curr->edges){
                    if(searchWord(word, i + 1, it)){
                        return true;
                    }
                }
                return false;
            }
            else if(curr == nullptr || curr->edges[word[i] - 'a'] == nullptr){
                return false;
            }else{
                curr = curr->edges[word[i] - 'a'];    
            }
        }
        return curr != nullptr && curr->isWord;
    }
    bool search(string word) {
        if(word.size() == 0)
            return true;
        return searchWord(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */