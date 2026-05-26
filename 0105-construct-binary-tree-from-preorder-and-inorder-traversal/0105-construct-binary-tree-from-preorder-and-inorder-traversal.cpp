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
    TreeNode* solve(int start, int end,int& i, vector<int>& preorder, vector<int>& inorder){
        if(start>end) return NULL;

        int rootVal = preorder[i];
        i++;
        int inIdx = mpp[rootVal];

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(start,inIdx-1,i,preorder,inorder);
        root->right = solve(inIdx+1,end,i,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0; i<n;i ++){
            mpp[inorder[i]] = i;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int idx = mpp[preorder[0]];
        int i = 1;
        root->left = solve(0,idx-1,i,preorder,inorder);
        root->right = solve(idx+1,n-1,i,preorder,inorder);

        return root;
    }
};