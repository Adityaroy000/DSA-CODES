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
    void helper(TreeNode* root,int key){
        if(key<root->val){
            if(root->left==NULL){
                root->left = new TreeNode(key);
            }else{
                helper(root->left,key);
            }
        }else{
            if(root->right == NULL){
                root->right = new TreeNode(key);
            }else{
                helper(root->right,key);
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1;i<n; i++){
            helper(root,preorder[i]);
        }
        return root;
    }
};