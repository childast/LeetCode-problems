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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        queue<pair<TreeNode*, int>> q;
        int depth = 0;
        q.push(make_pair(root, depth));
        vector<int> ans;
        int maxDepth = 0;
        while(!q.empty()){
            TreeNode* currNode = q.front().first;
            int currDepth = q.front().second;
            q.pop();
            if(maxDepth == currDepth){
                ans.push_back(currNode->val);
                maxDepth++;
            }
            
            if(currNode->right != nullptr)
                q.push(make_pair(currNode->right, currDepth + 1));
            
             if(currNode->left != nullptr)
                q.push(make_pair(currNode->left, currDepth + 1));
        }
        return ans;
    }
};