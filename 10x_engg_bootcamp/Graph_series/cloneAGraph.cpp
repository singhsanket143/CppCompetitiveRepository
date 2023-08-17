/*
//https://leetcode.com/problems/clone-graph/submissions/
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
    std::vector<Node*> nodeRegister; // whwnever we will create a new node, we will make an entry
    void dfs(Node* node, Node* clone) {
        for(auto neighbor : node->neighbors)  {
            if(not nodeRegister[neighbor->val]) {
                // if the neighbor we are visiting was never created and is getting visited for the first time
                Node* newNode = new Node(neighbor->val);
                nodeRegister[newNode->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs(neighbor, newNode);
            } else {
                // if the cloned node is already created, just setup the edges
                clone->neighbors.push_back(nodeRegister[neighbor->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL; // if the graph is empty, return null
        Node* clone = new Node(node->val);
        nodeRegister.resize(200, NULL);
        nodeRegister[clone->val] = clone;
        dfs(node, clone);
        return clone;
        
    }
};