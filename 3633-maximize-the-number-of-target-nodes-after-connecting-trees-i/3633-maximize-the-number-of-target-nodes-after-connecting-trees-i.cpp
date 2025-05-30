class Solution {
public:
    int n,m;
    void bfs(int node, vector<vector<int>>& adj,vector<int>& dist){
        queue<pair<int,int>>q;
        int s = adj.size();
        vector<int>vis(s,0);
        q.push({node,0});
        vis[node] = 1;
        dist[node] = 0;

        while(!q.empty()){
            auto [u,distance] = q.front();
            q.pop();

            for(auto& it:adj[u]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,distance+1});
                    dist[it] = distance+1;
                }
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        n = edges1.size()+1;
        m = edges2.size()+1;

        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);

        for(auto& it:edges1){
            int u = it[0];
            int v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto& it:edges2){
            int u = it[0];
            int v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        //for tree2
        int maxi = 0;
        for(int i=0;i<m;i++){
            vector<int>dist2(m,-1);
            bfs(i,adj2,dist2);

            int cnt = 0;
            for(int j=0;j<m;j++){
                if(dist2[j]!= -1 && dist2[j]<=(k-1)) cnt++;
            }
            maxi = max(maxi,cnt);
        }
      
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            vector<int>dist(n,-1);
            bfs(i,adj1,dist);

            int cnt = 0;
            for(int j=0;j<n;j++){
                if(dist[j]!= -1 && dist[j]<=k) cnt++;
            }

            ans[i] = maxi+cnt;
        }
        return ans;
    }
};