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
    int getSum(TreeNode* root){
        if(root == nullptr)
            return 0;
            
        return root->val + getSum(root->left) + getSum(root->right);
    }
    int update(TreeNode* root){
        if(root == nullptr)
            return 0;
        
        int val = root->val;
        int left = update(root->left);
        int right = update(root->right);
        root->val = abs(left - right);
        
        return val + left + right;
    }
    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        update(root);
        return getSum(root);
    }
};