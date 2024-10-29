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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            TreeNode* curr = node.first;
            int level=node.second;
            mp[level]=curr->val;
            if(curr->left) q.push({curr->left,level+1});
            if(curr->right) q.push({curr->right,level+1});
        }
        vector<int>temp;
        for(auto it1 : mp){
            temp.push_back(it1.second);
        }
        return temp;
    }
};