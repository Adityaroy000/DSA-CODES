class Solution {
public:
// rules for a binary tree:
// must have only one node whose indegree is 0 , if more than 1 have idegree as 0 then we have disconnected nodes. 
//every node other than root must have indegree 1 means only one parent
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){
            int l = leftChild[i];
            int r = rightChild[i];

            if(l != -1) {
                indeg[l]++;
                if(indeg[l] >= 2) return false;
            }

            if(r != -1) {
                indeg[r]++;
                if(indeg[r] >= 2) return false;
            }
        }

        int cnt = 0;
        int root = -1;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) {
                cnt++;
                root = i;
            }
        }

        if(cnt > 1 || cnt == 0) return false;
        vector<int>vec;
        queue<int>q;
        q.push(root);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            vec.push_back(node);

            if(leftChild[node] != -1) q.push(leftChild[node]);
            if(rightChild[node] != -1) q.push(rightChild[node]);
        }

        if(vec.size() == n) return true;
        return false;
    }
};