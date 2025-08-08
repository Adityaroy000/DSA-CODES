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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});

        int maxnode = 0;
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            maxnode = max(maxnode,end-start+1);
            for(int i=0;i<size;i++){
                auto it = q.front();
                TreeNode* currnode = it.first;
                long long idx = it.second-start;
                q.pop();
                if(currnode->left) q.push({currnode->left,(long long)2*idx+1});
                if(currnode->right) q.push({currnode->right,2*idx+2});
            }
        }
        return maxnode;
    }
};