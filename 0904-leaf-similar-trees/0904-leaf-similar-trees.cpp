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
    void solve(TreeNode* root,vector<int>& ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        solve(root->left,ans);
        solve(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return false;
        vector<int>ans,ans2;
        solve(root1,ans);
        solve(root2,ans2);

        if(ans == ans2) return true;
        return false;
    }
};