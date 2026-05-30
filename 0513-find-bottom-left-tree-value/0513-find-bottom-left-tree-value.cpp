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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = INT_MIN;
        int lastlev = -1;
        while(!q.empty()){
            auto [node,currlev] = q.front();
            q.pop();
            if(lastlev != currlev){
                ans = node->val;
                lastlev = currlev;
            }

            if(node->left) q.push({node->left,currlev+1});
            if(node->right) q.push({node->right,currlev+1});
        }

        return ans;
    }
};