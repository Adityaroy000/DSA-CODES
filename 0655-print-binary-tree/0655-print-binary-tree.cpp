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
    int m,n;
    int height(TreeNode* root) {
        if (!root) return -1; 
        return 1 + max(height(root->left), height(root->right));
    }

    void solve(vector<vector<string>>& ans,TreeNode* root,int r ,int c,int h){
        if(!root) return;

        ans[r][c] = to_string(root->val);

        if(root->left) solve(ans,root->left,r+1,c-(1<<(h-r-1)),h);
        if(root->right) solve(ans,root->right,r+1,c+(1<<(h-r-1)),h);

    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int m = h+1;
        int n = (1 << (h+1))-1;

        vector<vector<string>>ans(m,vector<string>(n,""));
        solve(ans,root,0,(n-1)/2,h);
        return ans;
    }
};