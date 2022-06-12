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
    void DFS(TreeNode* root, vector<int> & res, int lvl){
      if(res.size() > lvl){
        res[lvl] = max(res[lvl], root->val);
      }else{
        res.push_back(root->val);
      }
      if(root->left != NULL) DFS(root->left, res, lvl + 1);
      if(root->right != NULL) DFS(root->right, res, lvl + 1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root != NULL)
        DFS(root, res, 0);
        return res;
    }
};