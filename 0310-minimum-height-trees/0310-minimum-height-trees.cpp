class Solution {
public:
//Minimum height of a tree is achieved when it's rooted at its center.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Add initial leaves
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        vector<int> res;

        while (!q.empty()) {
            int size = q.size();
            res.clear();  // Clear previous level's nodes
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                res.push_back(node);

                for (int neighbor : adj[node]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return res;
    }
};