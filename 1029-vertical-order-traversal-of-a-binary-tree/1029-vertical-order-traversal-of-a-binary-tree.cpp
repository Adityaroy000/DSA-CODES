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
    map<int,map<int,vector<int>>>mpp;
    void solve(TreeNode* root, int row,int col){
        if(!root) return;

        mpp[col][row].push_back(root->val);
        solve(root->left,row+1,col-1);
        solve(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int r=0,c=0;
        solve(root,r,c);

        for(auto & p : mpp){
            vector<int>temp;
            for(auto &q : p.second){
                sort(q.second.begin(),q.second.end());
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};