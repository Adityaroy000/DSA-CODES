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

    CBTInserter(TreeNode* root) {
        node = root;
    }
    int depth = -1;
    bool check(){
        queue<TreeNode*>q;
        q.push(node);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            int cnt = 0;
            while(n--){
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                cnt++;
                q.pop();
            }
            if(cnt != pow(2,level)) {
                depth = level;
                return false;
            }
            level++;
        }
        return true;
    }
    vector<TreeNode*>temp;
    void solve(int odepth){
        queue<TreeNode*>q;
        q.push(node);
        int lev = 0;
        while(!q.empty()){
            int n = q.size();
            if(lev == odepth){
                while(!q.empty()){
                    temp.push_back(q.front());
                    q.pop();
                }
                break;
            }
            while(n--){
                TreeNode* currnode = q.front();
                if(currnode->left) q.push(currnode->left);
                if(currnode->right) q.push(currnode->right);
                q.pop();
            }
            lev++;
        }
    }
    int insert(int val) {
        if(check()){
            TreeNode* temp = node;
            while(temp->left && temp->right){
                temp = temp->left;
            }
            TreeNode* newnode = new TreeNode(val);
            int ans = temp->val;
            temp->left = newnode;
            return ans;
        }else{
            if(depth-2 < 0){
                if(!node->left){
                    node->left = new TreeNode(val);
                }else{
                    node->right = new TreeNode(val);
                }
                return node->val;
            }
            else{
                solve(depth-2);
                int ans = -1;
                for (auto it : temp) {
                    // try under it->left first (level order: left before right)
                    if (it->left) {
                        if (!it->left->left) {
                            it->left->left = new TreeNode(val);
                            ans = it->left->val;
                            return ans;
                        } else if (!it->left->right) {
                            it->left->right = new TreeNode(val);
                            ans = it->left->val;
                            return ans;
                        }
                    }

                    // then try under it->right
                    if (it->right) {
                        if (!it->right->left) {
                            it->right->left = new TreeNode(val);
                            ans = it->right->val;
                            return ans;
                        } else if (!it->right->right) {
                            it->right->right = new TreeNode(val);
                            ans = it->right->val;
                            return ans;
                        }
                    }
                }

            }
        }
        return -1;
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