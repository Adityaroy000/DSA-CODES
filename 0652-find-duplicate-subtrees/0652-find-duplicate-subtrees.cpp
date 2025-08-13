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
    unordered_map<string,int>mpp;
    vector<TreeNode*>ans;
    string serial(TreeNode* root){
        if(!root) return "#";
        
        string res = to_string(root->val);

        res += ","+ serial(root->left)+","+serial(root->right);

        mpp[res]++;
        if(mpp[res]==2){
            ans.push_back(root);
        }
        return res;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string temp = serial(root);

        return ans;
    }
};