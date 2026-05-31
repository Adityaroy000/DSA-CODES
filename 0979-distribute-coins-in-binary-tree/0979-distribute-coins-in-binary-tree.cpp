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
// total coins present at a node = node->val + leftSub_coin + rightSub_coin - 1 (-1 is for keeping one coin to itself as it is needed)
// then if this total coins is > 0 means surplus needs to send to its parent
// if total coins < 0 then scarcity needs that many from parent
    int ans = 0;
    int solve(TreeNode* root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);

        int tc = root->val + left + right - 1;

        ans += abs(tc);
        return tc;
    }
    int distributeCoins(TreeNode* root) {
        solve(root);

        return ans;
    }
};