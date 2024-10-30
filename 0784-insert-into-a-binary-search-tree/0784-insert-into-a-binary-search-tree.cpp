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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr = root;
        TreeNode* ptr;
        while(curr){
            ptr = curr;
            if(val<curr->val) curr = curr->left;
            else if(val > curr->val) curr = curr->right;
        }
        TreeNode* add = new TreeNode(val);
        if(val < ptr->val) ptr->left = add;
        else ptr->right = add;
        return root;
    }
};