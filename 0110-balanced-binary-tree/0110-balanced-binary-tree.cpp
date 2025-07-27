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
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>rh) return lh+1;
        else return rh+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        TreeNode* temp = root;
        
        while(temp){
            if(abs(height(temp->left)-height(temp->right)) <=1 && isBalanced(temp->left) && isBalanced(temp->right)){
                return true;
            }else{
                return false;
            }
        }
        
        return true;
    }
};