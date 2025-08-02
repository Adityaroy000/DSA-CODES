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
    int mini,smini = -1;
    void solve(TreeNode* root){
        if(!root) return;

        if(root->val < mini) {
            smini = mini;
            mini = root->val;
        }if(root->val > mini && (smini == -1 || root->val < smini)){
            smini = root->val;
        }

        solve(root->left);
        solve(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        mini = root->val;
        solve(root);

        return smini;
    }
};