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
    unordered_map<int,int>mpp;
    int maxfreq ;
    int treesum(TreeNode* root){
        if(!root) return 0;

        int sum = root->val+treesum(root->left)+treesum(root->right);
        mpp[sum]++;

        maxfreq = max(maxfreq,mpp[sum]);

        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxfreq = INT_MIN;

        int temp = treesum(root);

        vector<int>ans;
        for(auto& it:mpp){
            if(it.second == maxfreq){
                ans.push_back(it.first);
            }
        }

        return ans;
    }   
};