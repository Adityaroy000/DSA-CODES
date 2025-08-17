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
    int depth(TreeNode* root){
        if(!root) return -1;

        int lh = depth(root->left);
        int rh = depth(root->right);

        return 1+max(lh,rh);
    }
    vector<TreeNode*>temp;
    bool checkfilled(TreeNode* root,int depth){
        queue<TreeNode*>q;
        q.push(root);
        int currdepth = 0;

        while(!q.empty()&& currdepth <= depth-1){
            int n = q.size();
            int cnt = 0;
            while(n--){
                TreeNode* currnode = q.front();
                if(currdepth == depth-1){
                    temp.push_back(currnode);
                }
                q.pop();
                cnt++;
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);
            }
            if(cnt != pow(2,currdepth)) return false;
            currdepth++;
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        int level = depth(root);
        if(!checkfilled(root,level)) return false;

        vector<int>res;
        int n = temp.size();
        for(int i=0;i<n;i++){
            TreeNode* node = temp[i];
            if(node->left) res.push_back(node->val);
            else res.push_back(0);

            if(node->right) res.push_back(node->val);
            else res.push_back(0);
        }
        int idx = -1;
        for(int i=0;i<res.size();i++){
            if(res[i]==0) {
                idx = i;
                break;
            }
        }
        if(idx == -1) return true;
        for(int i=idx+1;i<res.size();i++){
            if(res[i]!=0) return false;
        }
  
        return true;
    }
};