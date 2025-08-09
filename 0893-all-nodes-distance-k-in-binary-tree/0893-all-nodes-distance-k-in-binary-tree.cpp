/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*,TreeNode*>mpp;
    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left) mpp[root->left] = root;
        inorder(root->left);

        if(root->right) mpp[root->right] = root;
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        inorder(root);

        unordered_set<TreeNode*>st;
        vector<int>ans;
        queue<TreeNode*>q;

        q.push(target);
        st.insert(target);

        int step = 0;
        while(!q.empty()){
            int n = q.size();
            if(step == k){
                while(!q.empty()){
                    TreeNode* temp = q.front();
                    q.pop();
                    ans.push_back(temp->val);
                }
                return ans;
            }
            while(n--){
                TreeNode* curr  = q.front();
                q.pop();
                st.insert(curr);

                if(curr->left && !st.count(curr->left)) {
                    q.push(curr->left);
                    st.insert(curr->left);
                }
                if(curr->right && !st.count(curr->right)) {
                    q.push(curr->right);
                    st.insert(curr->right);
                }
                if(mpp.count(curr) && !st.count(mpp[curr])) {
                    q.push(mpp[curr]);
                    st.insert(mpp[curr]);
                }
            }
            step++;
        }
        return ans;
    }
};