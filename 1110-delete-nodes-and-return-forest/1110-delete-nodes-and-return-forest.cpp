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
    unordered_set<int>st;
    vector<TreeNode*>ans;
    TreeNode* solve(TreeNode* root){
        if(!root) return NULL;

        if(!root->left && !root->right){
            if(st.count(root->val)) return NULL;
        }

        root->left = solve(root->left);
        root->right = solve(root->right);

        if(st.count(root->val)){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        int n = to_delete.size();
        for(int x : to_delete) st.insert(x);

        if(solve(root)) ans.push_back(root);

        return ans;
    }
};