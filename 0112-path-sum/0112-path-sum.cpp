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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) {
            if(targetSum- root->val == 0) return true;
            else return false;
        }
        bool f1 = false;
        bool f2 = false;
        if(root->left) f1 = hasPathSum(root->left,targetSum-(root->val));
        if(root->right) f2 = hasPathSum(root->right,targetSum-(root->val));

        return (f1||f2);

    }
};