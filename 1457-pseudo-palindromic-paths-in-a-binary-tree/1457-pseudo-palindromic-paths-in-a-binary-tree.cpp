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
    unordered_map<int,int>freq;
    int ans = 0;
    void solve(TreeNode* root){
        freq[root->val]++;
        
        if(!root->left && !root->right){
            int odd_cnt = 0;
            for(auto it : freq){
                if(it.second % 2 != 0) odd_cnt++;
            }

            if(odd_cnt<=1) ans++;
        }

        if(root->left) solve(root->left);
        if(root->right) solve(root->right);

        (freq[root->val]==1)?freq.erase(root->val):freq[root->val]--;
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);

        return ans;
    }
};