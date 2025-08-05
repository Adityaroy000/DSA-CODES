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
    map<int,map<int,int>>mpp;
    void solve(TreeNode* root,int row,int col){
        if(!root) return;
        
        if(mpp.count(row) == 0)
            mpp[row][col] = root->val;
        solve(root->right,row+1,col+1);
        solve(root->left,row+1,col-1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return ans;
        solve(root,0,0);

        for(auto & it:mpp){
            ans.push_back(it.second.begin()->second);
        }
        return ans;
    }
};