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
    void dfs(TreeNode * root, vector<int> & answer){
        if (root == nullptr)
            return;
        dfs(root->left, answer);
        dfs(root->right, answer);
        answer.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
          dfs(root, answer);      
          return answer;
    }
};