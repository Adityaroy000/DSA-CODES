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
    void solve(TreeNode* root,int num){
        if(!root) return;
        num = num*10 + root->val;

        if(!root->left && !root->right){
            ans.push_back(num);
            return;
        }

        solve(root->left,num);
        solve(root->right,num);

        num = num/10;
    }
    int sumNumbers(TreeNode* root) {
        int num = 0;
        solve(root,num);

        int sum = accumulate(ans.begin(),ans.end(),0);

        return sum;
    }
};