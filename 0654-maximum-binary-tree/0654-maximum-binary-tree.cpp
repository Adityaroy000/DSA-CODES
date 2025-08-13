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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;

        int n = nums.size();
        int maxi = INT_MIN;
        int idx = 0;

        for(int i=0;i<n;i++){
            if(nums[i]>maxi) {
                maxi = nums[i];
                idx = i;
            }
        }

        vector<int>left(nums.begin(),nums.begin()+idx);
        vector<int>right(nums.begin()+idx+1,nums.end());

        TreeNode* root = new TreeNode(maxi);

        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

       return root;
    }
};