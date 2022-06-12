/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    set<TreeNode*> vis;
    TreeNode* res = nullptr;
    
    bool findP(TreeNode* root, TreeNode* p){
        if(root == nullptr)
            return false;
        
        if(root == p){
            if(vis.count(root) && res == nullptr)
                res = root;
            vis.insert(root);
            return true;
        }
        
        bool ans = findP(root->left, p) || findP(root->right, p);
        if(ans){
            if(vis.count(root) && res == nullptr)
                res = root;
            vis.insert(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return root;
        
        findP(root, p);
        findP(root, q);
        return res;
    }
};