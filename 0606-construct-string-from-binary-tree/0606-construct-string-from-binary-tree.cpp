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
    string solve(TreeNode* root){
        if(!root) return "";

        string res = to_string(root->val);

        if(!root->left && !root->right){
            return res;
        }

        if(root->left){
            res += "(" + solve(root->left) + ")";
        }else{
            res+= "()";
        }

        if(root->right){
            res += "(" + solve(root->right) + ")";
        }
        
        return res;
    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};