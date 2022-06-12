/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int, vector<int>> levels;
    void buildLevels(TreeNode* node, int level){
        if(node != nullptr){
            levels[level].push_back(node->val);
            buildLevels(node->left, level + 1);
            buildLevels(node->right, level + 1);
        }
    }
    vector<vector<int>> levelsToVector(){
        vector<vector<int>> ans;
        for(auto level: levels){
            ans.push_back(level.second);
        }
        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        buildLevels(root, 0);
        return levelsToVector();
    }
};