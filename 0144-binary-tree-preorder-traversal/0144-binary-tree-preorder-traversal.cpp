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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                ans.push_back(curr->val);
                TreeNode* leftchild = curr->left;
                while(leftchild->right != NULL){
                    leftchild = leftchild->right;
                }
                leftchild->right = curr->right;
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return ans;
    }
};