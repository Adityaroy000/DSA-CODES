/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    bool flag = false;
    void solve(TreeNode* root,TreeNode* target){
        if(!root) return;

        if(root->val == target->val){
            ans = root;
            flag = true;
            return;
        }

        if(!flag) solve(root->left,target);
        if(!flag) solve(root->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(cloned,target);
        return ans;
    }
};