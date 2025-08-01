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
    vector<string>ans;
    void solve(TreeNode* root,string temp){
        if(!root->left && !root->right){
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp += to_string(root->val);
        temp += "->";

        if(root->left) solve(root->left,temp);
        if(root->right) solve(root->right,temp);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        string temp = "";
        solve(root,temp);
        
        return ans;
    }
};