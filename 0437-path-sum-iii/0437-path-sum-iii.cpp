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
    unordered_map<long long,int>mpp;
    int cnt = 0;
    void solve(TreeNode* root,int target,long long sum){
        if(!root) return;

        sum += (long long)root->val;
        long long req = sum-target;
        if(mpp.find(req)!=mpp.end()){
            cnt += mpp[req];
        }
        mpp[sum]++;

        solve(root->left,target,sum);
        solve(root->right,target,sum);

        if(mpp[sum] == 1) mpp.erase(sum);
        else{
            mpp[sum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        mpp[0] = 1;
        long long sum = 0;
        solve(root,targetSum,sum);
        return cnt;
    }
};