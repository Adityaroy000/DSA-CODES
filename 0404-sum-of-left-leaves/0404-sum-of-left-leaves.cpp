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
    int sum = 0;
    void solve(TreeNode* root, bool flag){
        if(!root->left && !root->right && flag){
            sum += root->val;
            return;
        }

        if(root->left) solve(root->left,true);
        if(root->right) solve(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        bool flag = false;
        solve(root,flag);

        return sum;
    }
};