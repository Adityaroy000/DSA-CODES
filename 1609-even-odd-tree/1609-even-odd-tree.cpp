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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            int n = q.size();
            int l = q.front().second;
            int lastel;
            if(l%2 == 0) lastel = INT_MIN;
            else lastel = INT_MAX;
            while(n--){
                auto [curr, lev] = q.front();
                q.pop();

                if(lev % 2 == 0){
                    if(curr->val % 2 == 0) return false;
                    if(curr->val > lastel) {
                        lastel = curr->val;
                    }else return false;
                }else{
                    if(curr->val % 2 != 0) return false;
                    if(curr->val < lastel) {
                        lastel = curr->val;
                    }else return false;
                }

                if(curr->left) q.push({curr->left,lev+1});
                if(curr->right) q.push({curr->right,lev+1});
            }
        }
        return true;
    }
};