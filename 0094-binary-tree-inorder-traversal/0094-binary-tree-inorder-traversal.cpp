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
    void i(TreeNode* root,vector<int>& temp){
        if(root==NULL) return;
        if(root!=NULL){
            i(root->left,temp);
            temp.push_back(root->val);
            i(root->right,temp);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>temp;
        i(root,temp);
        return temp;
    }
};