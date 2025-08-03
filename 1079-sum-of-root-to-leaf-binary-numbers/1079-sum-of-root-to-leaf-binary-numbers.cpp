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
        if(!root) return;
        if(!root->left && !root->right){
            temp += to_string(root->val);
            ans.push_back(temp);
            return;
        }
        temp += to_string(root->val);
        solve(root->left,temp);
        solve(root->right,temp);
    }
    int sumRootToLeaf(TreeNode* root) {
        string temp = "";
        solve(root,temp);
        
        int sum = 0;
        for(int i=0;i<ans.size();i++){
            int number = stoi(ans[i], nullptr, 2); 
            sum += number;
        }

        return sum;
    }
};