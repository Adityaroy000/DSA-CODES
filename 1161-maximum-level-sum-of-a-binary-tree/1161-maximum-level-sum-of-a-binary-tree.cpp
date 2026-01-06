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
    int maxLevelSum(TreeNode* root) {
        pair<int,int>ans = {INT_MIN,1};

        queue<pair<TreeNode*,int>>q;
        int currlev = 1;
        q.push({root,1});
        int sum = 0;
        while(!q.empty()){
            TreeNode* currnode = q.front().first;
            int lev = q.front().second;
            int el = currnode->val;
            q.pop();
            if(lev == currlev){
                sum+=el;
            }else{
                if(sum > ans.first){
                    ans = {sum,currlev};
                }
                sum = el;
                currlev = lev;
            }
            if(currnode->left) q.push({currnode->left,lev+1});
            if(currnode->right) q.push({currnode->right,lev+1});
        }
        if(sum > ans.first){
            ans = {sum,currlev};
        }
        return ans.second;
    }
};