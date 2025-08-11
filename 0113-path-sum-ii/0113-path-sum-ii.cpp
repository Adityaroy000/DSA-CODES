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
    vector<vector<int>>ans;
    void solve(TreeNode* root,int targetSum,vector<int>temp){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            int sum = accumulate(temp.begin(),temp.end(),0);
            if(sum == targetSum){
                ans.push_back(temp);
            }else{
                return;
            }
        }
        temp.push_back(root->val);
        solve(root->left,targetSum,temp);
        solve(root->right,targetSum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        
        vector<int>temp;
        solve(root,targetSum,temp);

        return ans;
    }
};