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
    void inorder(TreeNode* root,vector<int>& temp){
        if(!root) return;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>temp;
        inorder(root,temp);
        int left = 0;
        int right = temp.size()-1;
        int sum = 0;
        while(left<right){
            sum = temp[left]+temp[right];
            if(sum>k){
                right--;
            }
            else if(sum<k){
                left++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};