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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>temp;
        stack<TreeNode*>st;
        TreeNode* lastvisited = NULL;
        TreeNode* curr = root;
        while(curr!=NULL||!st.empty()){
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* topNode = st.top();
            if(topNode->right!=NULL && lastvisited!= topNode->right ){
                curr = topNode->right;
            }else{
                temp.push_back(topNode->val);
                lastvisited = topNode;
                st.pop();
            }
        }
        return temp;
    }
};