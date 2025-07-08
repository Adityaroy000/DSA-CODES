class Solution {
public:

    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<vector<int>>adj(n);
        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt-1;
    }
};