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
    vector<int>ans;
    void solve(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;

        int val = root->val;
        solve(root);
        for(int i=0;i<ans.size();i++){
            if(ans[i]!= val) return false;
        }
        return true;
    }
};