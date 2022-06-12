/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string path = "";
    string nodeToString(TreeNode* node){
        string ans = to_string(node->val);
        ans += path;
        ans += '.';
        return ans;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        
        string ans = nodeToString(root);
        path += 'L';
        ans += serialize(root->left);
        path.pop_back();
        path += 'R';
        ans += serialize(root->right);
        path.pop_back();
        return ans;
    }
    
    map<string, TreeNode*> mp;
    
    void stringToNode(string node){
        string value = "";
        string path = "";
        for(int i = 0; i < node.size(); i++){
            if(('0' <= node[i] && '9' >= node[i]) || node[i] == '-')
                value += node[i];
            else
                path += node[i];
        }
        mp[path] = new TreeNode(stoi(value));
    }
    
    TreeNode* buildTree(string path){
        if(!mp.count(path))
            return nullptr;
        
        mp[path]->left = buildTree(path + 'L');
        
        mp[path]->right = buildTree(path + 'R');
        
        return mp[path];
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        
        
        int idx = 0;
        string currNode = "";
        while(idx < data.size()){
            if(data[idx] != '.')
            {
                currNode += data[idx];
            }
            else
            {
                stringToNode(currNode);
                currNode = "";
            }
            idx++;
        }
        
        cout << data << "\n";
        return buildTree("");
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));