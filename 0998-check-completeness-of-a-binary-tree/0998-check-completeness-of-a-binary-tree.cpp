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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool foundGap = false;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* currnode = q.front();
                q.pop();

                if(foundGap && (currnode->left || currnode->right)) return false;
                
                if(!currnode->left) {
                    foundGap = true;
                    if(currnode->right) return false;
                }else q.push(currnode->left);

                if(!currnode->right) foundGap = true;
                else q.push(currnode->right);
            }
        }
        return true;
    }
};