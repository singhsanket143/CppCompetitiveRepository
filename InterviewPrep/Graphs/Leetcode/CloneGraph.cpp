#include <iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<int, Node*> nodes;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        if(nodes.find(node->val)!=nodes.end()) {
            return nodes[node->val];
        }
        vector<Node*> v;
        Node* clone = new Node(node->val, v);
        nodes[clone->val] = clone;
        for(Node* n: node->neighbors) {
            clone->neighbors.push_back(cloneGraph(n));
        }
        return clone;
    }
};