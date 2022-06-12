/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        
        queue<Node*> currLevel, nextLevel;
        currLevel.push(root);
        while(!currLevel.empty()){
            while(!currLevel.empty()){
                Node* currNode = currLevel.front();
                currLevel.pop();
                if(!currLevel.empty())
                    currNode->next = currLevel.front();
                else
                    currNode->next = nullptr;
                if(currNode->left != nullptr && currNode->right != nullptr){
                    nextLevel.push(currNode->left);
                    nextLevel.push(currNode->right);
                }
            }
            currLevel = nextLevel;
            nextLevel = queue<Node*>();
        }
        
        return root;
    }
};