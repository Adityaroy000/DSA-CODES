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
    int n;
    vector<int>ans;
    int idx;
    bool pre(TreeNode* root,vector<int>& voyage){
        if(!root ) return true;

        if(root->val != voyage[idx]) return false;

        idx++;
        if(idx<n){
            if(root->left ){
                if(root->left->val != voyage[idx]){
                    if(root->right && root->right->val == voyage[idx]){
                        swap(root->left,root->right);
                        ans.push_back(root->val);
                    }else return false;
                }
            }
            else if(root->right ){
                if(root->right->val != voyage[idx]){
                   return false;
                }
            }
        }

        pre(root->left,voyage);
        pre(root->right,voyage);

        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {

        n = voyage.size();
        idx = 0;
        if(pre(root,voyage)){
            if(idx == n) return ans;
        }
       return {-1};
    }
};