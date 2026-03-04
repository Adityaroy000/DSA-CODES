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
    bool exist(int idx,int h, TreeNode* root){
        int l = 0;
        int r = (1<<(h-1))-1;

        for(int i=0;i<h-1;i++){
            int mid = l+(r-l)/2;
            if(idx <= mid){
                root = root->left;
                r = mid;
            }else{
                root = root->right;
                l=mid+1;
            }
            if(root == NULL) return false;
        }
        return true;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int h = 0;
        TreeNode* temp = root;
        while(temp){
            h++;
            temp = temp->left;
        }

        int nodesBeforeLastLevel = (1<<(h-1)) - 1;

        int l=0,r = (1<<(h-1))-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(exist(mid,h,root)){
                l = mid+1;
            }else r = mid-1;
        }

        return nodesBeforeLastLevel+l;

    }
};