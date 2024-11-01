/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
private: 
    stack<TreeNode* >st;
    bool isreverse;
public:
    BSTIterator(TreeNode* root,bool reverse){
        isreverse=reverse;
        pushall(root);
    }
    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            if(isreverse) root = root->right;
            else root = root->left;
        }
    }
    int next(){
        TreeNode* curr = st.top();
        st.pop();
        if(isreverse) pushall(curr->left);
        else pushall(curr->right);
        return curr->val;
    }
    bool hasnext(){
        return !st.empty();
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator left(root,false);
        BSTIterator right(root,true);
        int leftval = left.next();
        int rightval = right.next();
        while(leftval<rightval){
            int sum = leftval+rightval;
            if(sum==k) return true;
            else if(sum<k) leftval = left.next();
            else rightval = right.next();
        }
        return false;
    }
};