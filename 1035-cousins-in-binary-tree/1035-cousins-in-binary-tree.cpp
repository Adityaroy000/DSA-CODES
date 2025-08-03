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
    int xp = -1,yp = -1,xd = -1,yd = -1;
    void solve(TreeNode* root,TreeNode* parent,int depth,int x,int y){
        if(!root) return;
        if(root->val == x){
            xp = parent->val;
            xd = depth;
        }else if(root->val == y){
            yp = parent->val;
            yd = depth;
        }
        solve(root->left,root,depth+1,x,y);
        solve(root->right,root,depth+1,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,root,0,x,y);

        if(xd == yd && xp != yp) return true;
        return false;
    }
};