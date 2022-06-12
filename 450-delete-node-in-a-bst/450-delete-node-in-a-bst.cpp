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
    TreeNode* getMostLeft(TreeNode* node){
        while (node != nullptr && node->left != nullptr)
            node = node->left;
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        
        if (root->val != key){
            if(root->val > key){
                root->left = deleteNode(root->left, key);
            }
            else{
                root->right = deleteNode(root->right, key);
            }
            return root;
        }
        TreeNode* rootRight = root->right;
        TreeNode* leftMostInRight = getMostLeft(rootRight);
        if (leftMostInRight == nullptr)
            return root->left;
        
        leftMostInRight->left = root->left;
        return root->right;
    }
};