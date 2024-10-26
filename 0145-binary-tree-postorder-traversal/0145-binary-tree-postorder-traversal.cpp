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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>temp;
        stack<TreeNode*>st;
        stack<TreeNode*>s2;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            s2.push(curr);
            if(curr->left!=NULL) st.push(curr->left);
            if(curr->right!=NULL) st.push(curr->right);
        }
        while(!s2.empty()){
            temp.push_back(s2.top()->val);
            s2.pop();
        }
        return temp;
    }
};