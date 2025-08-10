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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int& idx,int start,int end){
        if(start>end || idx < 0) return NULL;
        int rootval = postorder[idx];
        int inroot = mpp[rootval];
        idx--;

        TreeNode* root = new TreeNode(rootval);
        root->right = solve(inorder,postorder,idx,inroot+1,end);
        root->left = solve(inorder,postorder,idx,start,inroot-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        return solve(inorder,postorder,idx,0,n-1);
    }
};