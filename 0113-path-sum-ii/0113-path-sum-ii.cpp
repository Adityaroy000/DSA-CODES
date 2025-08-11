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
    void solve(TreeNode* root,int targetSum,vector<int>temp,int sum){
        if(!root) return;
        if(!root->left && !root->right){
            temp.push_back(root->val);
            sum += root->val;
            if(sum == targetSum){
                ans.push_back(temp);
            }else return;
        }
        temp.push_back(root->val);
        sum += root->val;
        solve(root->left,targetSum,temp,sum);
        solve(root->right,targetSum,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        
        vector<int>temp;
        int sum = 0;
        solve(root,targetSum,temp,sum);

        return ans;
    }
};