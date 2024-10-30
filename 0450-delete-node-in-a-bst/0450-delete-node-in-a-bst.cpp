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
    int largest(TreeNode* root){
        TreeNode* curr = root;
        if(root->right==NULL) return root->val;

        while(curr->right!=NULL){
            curr = curr->right;
        }
        return curr->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }else{
            if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }else if(root->left==NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }else if(root->right && root->left){
                int temp = largest(root->left);
                root->val = temp;
                root->left = deleteNode(root->left,temp);
            }
        }
        return root;
    }
};