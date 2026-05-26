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
    vector<TreeNode*>vec;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        vec.push_back(root);
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);

        int n = vec.size();
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        bool found = false;

        for(int i=1;i<n;i++){
            if(vec[i]->val < vec[i-1]->val){
                if(found){
                    second = vec[i];
                    break;
                }
                first = vec[i-1];
                second = vec[i];
                found = true;
            }
        }
        swap(first->val,second->val);
        return;
    }
};