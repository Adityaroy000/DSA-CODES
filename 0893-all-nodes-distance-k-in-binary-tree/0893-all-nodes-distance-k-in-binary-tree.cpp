/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    vector<vector<int>>graph = vector<vector<int>>(501);;
    void build(TreeNode* root){
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            build(root->left);
        }
        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            build(root->right);
        }
    }
    
    void solve(int val,vector<int>& vis,int step,int k){
        vis[val] = 1;
        if(step == k){
            ans.push_back(val);
        }
        for(int i=0;i<graph[val].size();i++){
            if(!vis[graph[val][i]]){
                solve(graph[val][i],vis,step+1,k);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        build(root);
        vector<int>vis(501);
        int val = target->val;
        
        solve(val,vis,0,k);

        return ans;
    }
};