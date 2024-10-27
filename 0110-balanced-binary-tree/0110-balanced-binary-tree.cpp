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
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh>rh) return lh+1;
        else return rh+1;
    }
    bool isBalanced(TreeNode* root) {
        TreeNode* visited = NULL;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr!=NULL || !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* topnode = st.top();
            if(topnode->right && visited!=topnode->right){
                curr = topnode->right;
            }else{
                int bf = height(topnode->left)-height(topnode->right);
                if(bf >= 2 || bf <= -2){
                    return false;
                }
                visited = topnode;
                st.pop();
            }
        }
        return true;
    }
};