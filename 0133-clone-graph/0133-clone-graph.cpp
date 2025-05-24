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
    void dfs(Node* node,Node* clone_node,unordered_map<Node*,Node*>& mpp){
        for(auto& adj:node->neighbors){
            if(mpp.find(adj)==mpp.end()){
                Node* clone = new Node(adj->val);
                mpp[adj] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(adj,clone,mpp);
            }else{
                clone_node->neighbors.push_back(mpp[adj]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* clone_node = new Node(node->val);
        unordered_map<Node*,Node*>mpp;
        mpp[node] = clone_node;

        dfs(node,clone_node,mpp);
        return clone_node;
    }
};