#include <iostream>
#include <vector>
using namespace std;
/*
// Definition for a Node.

*/
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
class Solution {
public:
    vector<Node*> nodeRegister;
    
    void dfs(Node* actual, Node* clone) {
        for(auto neighbor : actual->neighbors) {
            if(not nodeRegister[neighbor->val]) {
                // create the neighbor for the first time
                Node* newNode = new Node(neighbor->val);
                nodeRegister[newNode->val]  = newNode;
                clone->neighbors.push_back(newNode);
                dfs(neighbor, newNode);
            } else {
                clone->neighbors.push_back(nodeRegister[neighbor->val]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        nodeRegister.resize(110, NULL); // this array contains ref to the created nodes
        nodeRegister[clone->val] = clone;
        dfs(node, clone);
        return clone;
    }
};
int main() {

    return 0;
}