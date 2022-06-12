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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return root;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* currNode;
        while (!q.empty()){
            currNode = q.front();
            q.pop();
            TreeNode* inter = currNode->left;
            currNode->left = currNode->right;
            currNode->right = inter;
            if (currNode->left != nullptr)
                q.push(currNode->left);
            if(currNode->right != nullptr)
                q.push(currNode->right);
        }
        return root;
    }
};