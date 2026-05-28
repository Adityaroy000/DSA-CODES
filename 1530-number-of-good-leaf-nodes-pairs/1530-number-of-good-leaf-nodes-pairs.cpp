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
    int cnt = 0;
    vector<int> solve(TreeNode* root,int distance){
        if(!root) return {};
        if(!root->right && !root->left) {
            return {1};
        }


        vector<int>ans;

        vector<int>left = solve(root->left, distance);
        vector<int>right = solve(root->right, distance);

        for(int l : left){
            for(int r : right){
                int dis = l+r;
                if(dis <= distance) cnt++;
            }
        }
        for(int i=0;i<left.size();i++) left[i]++;
        for(int i=0;i<right.size();i++) right[i]++;

        for(int x: left) ans.push_back(x);
        for(int x: right) ans.push_back(x);

        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        solve(root,distance);

        return cnt;
    }
};