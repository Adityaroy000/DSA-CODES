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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        TreeNode* curr= root;
        int cnt = 0;
        while(curr){
            if(val<curr->val){
                curr = curr->left;
            }
            else if(val>curr->val){
                curr = curr->right;
            }
            else {
                cnt = 1;
                break;
            }
        }
        if(cnt == 1){
            return curr;
        }else{
            return NULL;
        }
    }
};