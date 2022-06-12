/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> copiedNodes;
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        
        vector<Node*> neighborsCopy;
        Node* nodeCopy = new Node();
        copiedNodes[node->val] = nodeCopy;
        for(int i = 0; i < node->neighbors.size(); i++){
            if(node->neighbors[i] != nullptr && !copiedNodes.count(node->neighbors[i]->val))
                neighborsCopy.push_back(cloneGraph(node->neighbors[i]));
            else
                neighborsCopy.push_back(copiedNodes[node->neighbors[i]->val]);
        }
        nodeCopy->val = node->val;
        nodeCopy->neighbors = neighborsCopy;
        return nodeCopy;
    }
};