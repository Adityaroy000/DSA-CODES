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
    int maxsum;
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int koi_ek_achha =  max(l,r)+root->val;
        int dono_achha = root->val+l+r;
        int only_root_achha  = root->val;

        maxsum = max({maxsum,koi_ek_achha,dono_achha,only_root_achha});

        return max(koi_ek_achha,only_root_achha); 
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);

        return maxsum;
    }
};