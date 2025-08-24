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
        while(curr){
            Node* newnode = new Node(curr->val);
            newnode->next = curr->next;
            curr->next = newnode;
            curr = newnode->next;
        }

        curr = head;
        while(curr){
            Node* cnode = curr->next;
            if(curr->random)
                cnode->random = curr->random->next;
            else cnode->random = NULL;
            curr = cnode->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        curr = head;
        while(curr){
            res->next = curr->next;
            res = res->next;
            curr->next = curr->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};