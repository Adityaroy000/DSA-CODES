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
    TreeNode* build(vector<int>& preorder,int& idx,vector<int>& inorder,int instart,int inend){
        if(instart>inend || idx >= preorder.size()) return NULL;

        int rootval = preorder[idx];
        int inroot = mpp[rootval];
        idx++;
        TreeNode* root = new TreeNode(rootval);
        root->left = build(preorder,idx,inorder,instart,inroot-1);
        root->right = build(preorder,idx,inorder,inroot+1,inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        int idx = 0;
        TreeNode* root = build(preorder,idx,inorder,0,n-1);
        return root;
    }
};