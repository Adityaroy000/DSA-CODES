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
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;

        flatten(root->left);
        flatten(root->right);

        if(root->left){
            TreeNode* leftchild = root->left;
            root->left = NULL;
            TreeNode* rightchild = NULL;
            if(root->right) rightchild = root->right;

            root->right = leftchild;
            
            while(leftchild->right != NULL){
                leftchild = leftchild->right;
            }
            leftchild->right = rightchild;
        }
    }
};