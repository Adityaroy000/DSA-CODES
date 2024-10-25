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
    void p(TreeNode* root,vector<int>& temp){
        if(root==NULL) return;
        if(root!=NULL){
            temp.push_back(root->val);
            p(root->left,temp);
            p(root->right,temp);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>temp;
        p(root,temp);
        return temp;
    }
};