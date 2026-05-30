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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;

        int rem = n-1;
        if(rem == 0){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        for(int i=1;i<=rem;i+=2){
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(rem-i);

            for(int i=0;i<left.size();i++){
                for(int j=0;j<right.size();j++){
                    TreeNode* root = new TreeNode(0);
                    root->left = left[i];
                    root->right = right[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};