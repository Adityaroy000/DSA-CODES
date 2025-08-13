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
    void solve(TreeNode* root,int val, int depth,int currdepth){
        if(!root) return;

        if(currdepth == depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            TreeNode* newnodeone = new TreeNode(val);
            TreeNode* newnodetwo = new TreeNode(val);
            root->left = newnodeone;
            root->right = newnodetwo;

            newnodeone->left = left;
            newnodetwo->right = right;
            return;
        }

        solve(root->left,val,depth,currdepth+1);
        solve(root->right,val,depth,currdepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }

        solve(root,val,depth,1);
        return root;
    }
};