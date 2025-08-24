/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        unordered_map<Node*,Node*>mpp;
        mpp[NULL] = NULL;
        while(curr){
            Node* newnode = new Node(curr->val);
            mpp[curr] = newnode;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node* newnode = mpp[curr];
            newnode->next = mpp[curr->next];
            newnode->random = mpp[curr->random];

            curr = curr->next;
        }
        return mpp[head];
    }
};