/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<TreeNode*> nodesList;
    TreeNode* buildTree(int start, int finish){
        int mid = (start + finish) / 2;
        TreeNode* curr = nodesList[mid];
        
        if(start == finish)
            return curr;
        
        if(start <= mid - 1)
            curr->left = buildTree(start, mid - 1);
        if(mid + 1 <= finish)
            curr->right = buildTree(mid + 1, finish);
        return curr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        while(head != nullptr){
            nodesList.push_back(new TreeNode(head->val));
            head = head->next;
        }
        return buildTree(0, nodesList.size() - 1);
    }
};