class Solution {
public:
    int numTrees(int n) {
        // dp[i] = number of unique BSTs that can be formed using i nodes
        vector<int>dp(n+1,1); // 1 bcz there is always one way to build a bst which is empty 

        for(int node=2;node<=n;node++){
            int total = 0;
            for(int root=1;root<=node;root++){
                // If 'root' is chosen as the root node:
                // left subtree will contain (root - 1) nodes
                // right subtree will contain (node - root) nodes

                // Number of ways to form left subtree  = dp[root - 1]
                // Number of ways to form right subtree = dp[node - root]

                // Each left subtree can pair with every right subtree
                // so total combinations for this root are:
                total += dp[root-1]*dp[node-root];
            }
            dp[node] = total;
        }

        return dp[n];
    }
};