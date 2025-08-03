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
    vector<int>ans,ans2;
    void solve(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        solve(root->left);
        solve(root->right);
    }
    void solve2(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right){
            ans2.push_back(root->val);
            return;
        }
        solve2(root->left);
        solve2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return false;

        solve(root1);
        solve2(root2);

        if(ans == ans2) return true;
        return false;
    }
};