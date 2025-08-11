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
    Node* nextchild(Node* root){
        while(root){
            if(root->left) return root->left;
            if(root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }
    void solve(Node* root){
        if(!root) return;

        if(root->left){
            if(root->right) root->left->next = root->right;
            else root->left->next = nextchild(root->next);
        }
        if(root->right){
            root->right->next = nextchild(root->next);
        }

        solve(root->right);
        solve(root->left);
    }
    Node* connect(Node* root) {
        if(!root) return NULL;

        solve(root);

        return root;
    }
};