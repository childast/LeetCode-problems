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
    bool isValid(long long minVal, long long maxVal, TreeNode* node){
        if (node == nullptr)
            return true;
        if(node->val >= maxVal || node->val <= minVal)
            return false;
        return isValid(minVal, node->val, node->left) && isValid(node->val, maxVal, node->right);
    }
    bool isValidBST(TreeNode* root) {
        long long maxVal = 2147483648;
        long long minVal = -2147483649;
        return isValid(minVal, maxVal, root);
    }
};