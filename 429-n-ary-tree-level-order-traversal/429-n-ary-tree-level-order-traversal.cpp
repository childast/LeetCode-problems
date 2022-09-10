/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr){
            return {};
        }
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            queue<Node*> currQ;
            vector<int> currV;
            while(!q.empty()){
                Node* curr = q.front();
                q.pop();
                currV.push_back(curr->val);
                for(auto it: curr->children){
                    currQ.push(it);
                }
            }
            ans.push_back(currV);
            q = currQ;
        }
        return ans;
    }
};