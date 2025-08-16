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
class CBTInserter {
public:
    TreeNode* node;
    queue<TreeNode*>q;

    CBTInserter(TreeNode* root) {
        node = root;
        queue<TreeNode*>temp;
        temp.push(node);
        while(!temp.empty()){
            TreeNode* curr = temp.front();
            temp.pop();
            if(!(curr->left && curr->right)) q.push(curr);
            if(curr->left) temp.push(curr->left);
            if(curr->right) temp.push(curr->right);
        }
    }
     
    int insert(int val) {
        TreeNode* curr = q.front();
        TreeNode* newnode = new TreeNode(val);

        if(!curr->left ){
            curr->left = newnode;
        }else{
            curr->right = newnode;
            q.pop();
        }
        q.push(newnode);
        return curr->val;
    }
    
    TreeNode* get_root() {
        return node;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */