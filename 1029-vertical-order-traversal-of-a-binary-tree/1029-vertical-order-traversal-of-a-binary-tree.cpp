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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int x = p.second.first,y = p.second.second;
            mpp[x][y].insert(curr->val);
            if(curr->left) q.push({curr->left,{x-1,y+1}});
            if(curr->right) q.push({curr->right,{x+1,y+1}});
        }
        vector<vector<int>>ans;
        for(auto p:mpp){
            vector<int>col;
            for(auto it : p.second){
                col.insert(col.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};