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
    int tiltsum = 0;
    int solve(TreeNode* root){
        if(!root->left && !root->right){
            return root->val;
        }
        int leftsum = 0;
        if(root->left) leftsum += solve(root->left);
        int rightsum = 0;
        if(root->right) rightsum += solve(root->right);

        tiltsum += abs(leftsum-rightsum);

        return leftsum+rightsum+root->val;
    }
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        solve(root);

        return tiltsum;
    }
};