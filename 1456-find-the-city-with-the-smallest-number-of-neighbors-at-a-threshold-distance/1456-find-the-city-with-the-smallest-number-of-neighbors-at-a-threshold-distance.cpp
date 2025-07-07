class Solution {
public:
    typedef pair<int,int> p;
    vector<int> dijkstra(int n,int src,vector<vector<pair<int,int>>>& adj){
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,src});

        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(wt+distance < dist[adjNode]){
                    dist[adjNode] = wt+distance;
                    pq.push({wt+distance,adjNode});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            vector<int>ans = dijkstra(n,i,adj);
            int cnt = 0;
            for(int j=0;j<ans.size();j++){
                if(i!=j && ans[j] != INT_MAX && ans[j] <= distanceThreshold){
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        
        int mini = INT_MAX;
        int city = -1;
        for(int i=0;i<res.size();i++){
            if(mini >= res[i]) {
                mini = res[i];
                city = i;
            }
        }
        return city;
    }
};