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
        if(val < ptr->val){
            TreeNode* add = new TreeNode(val);
            ptr->left = add;
            add->left = NULL;
            add->right = NULL;
        }else{
            TreeNode* add = new TreeNode(val);
            ptr->right = add;
            add->left = NULL;
            add->right = NULL;
        }
        return root;
    }
};