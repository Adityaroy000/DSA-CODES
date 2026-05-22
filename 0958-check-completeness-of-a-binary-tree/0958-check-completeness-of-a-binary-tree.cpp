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
    int findLevel(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);

        int level = -1;
        while(!q.empty()){
            int n = q.size();
            level++;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return level;
    }
    bool isCompleteTree(TreeNode* root) {
        if(!root->left && !root->right) return true;
        int level = findLevel(root);

        queue<TreeNode*>q;
        q.push(root);

        int currLev = -1;
        while(!q.empty()){
            currLev++;
            int n = q.size();
            bool left=true,right=true;
            while(n--){
                TreeNode* curr = q.front();
                q.pop();
                if(currLev == level-1){
                    if(left == true && right == false) {
                        if(curr->left || curr->right) return false;
                    }else if(left == false && right == false) {
                        if(curr->left || curr->right) return false;
                    }
                    if(!curr->left) left = false;
                    if(!curr->right) right = false;

                    if(left == false && right) return false;
                }else{
                    if(!curr->left) left = false;
                    if(!curr->right) right = false;
                    
                    if(!left || !right) return false;
                    
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
            }
        }
        return true;
    }
};