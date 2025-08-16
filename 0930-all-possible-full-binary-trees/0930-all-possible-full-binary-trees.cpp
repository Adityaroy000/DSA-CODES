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
    unordered_map<int,vector<TreeNode*>>mpp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};

        vector<TreeNode*>ans;
        if(n == 1){
            return {new TreeNode(0)};
        }

        if(mpp.count(n)!=0) return mpp[n];

        for(int i=1;i<n;i+=2){
            int right = n-1-i;

            vector<TreeNode*>leftTree = allPossibleFBT(i);
            vector<TreeNode*>rightTree = allPossibleFBT(right);

            for(auto l : leftTree){
                for(auto r : rightTree){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mpp[n] = ans;
    }
};