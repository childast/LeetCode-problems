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
    bool areSymmetric(TreeNode* leftTree, TreeNode* rightTree){
        if(leftTree == nullptr && rightTree == nullptr)
            return true;
        
        if(leftTree == nullptr || rightTree == nullptr)
            return false;
        
        if(leftTree->val != rightTree->val)
            return false;
        return areSymmetric(leftTree->left, rightTree->right) && areSymmetric(leftTree->right, rightTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        
        return areSymmetric(root->left, root->right);
    }
};