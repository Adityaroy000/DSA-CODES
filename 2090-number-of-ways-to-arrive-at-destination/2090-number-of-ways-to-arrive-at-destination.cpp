class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<long long>ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<>>q;

        dist[0] = 0;
        ways[0] = 1;

        q.push({0,0});

        while(!q.empty()){
            long long wt = q.top().first;
            int node = q.top().second;
            q.pop();

            if(wt>dist[node]) continue;

            for(auto it:adj[node]){
                int adjnode = it.first;
                long long adjwt = it.second;

                long long newdist = wt+adjwt;
                if(dist[adjnode]>newdist){
                    dist[adjnode] = newdist;
                    ways[adjnode] = ways[node];
                    q.push({newdist,adjnode});
                }else if(newdist == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }

        }

        return ways[n-1]%mod;
    }
};