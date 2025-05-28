class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto& it:flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];

            adj[u].push_back({v,cost});
        }

        queue<pair<pair<int,int>,int>>q;

        vector<int>cost(n,1e6);

        q.push({{src,0},0});
        cost[src]= 0;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int node = temp.first.first;
            int wt = temp.first.second;
            int stop = temp.second;

            if(stop>k) continue;

            for(auto& it:adj[node]){
                int v = it.first;
                int currcost = it.second;

                if(wt+currcost<=cost[v]){
                    cost[v] = wt+currcost;
                    q.push({{v,wt+currcost},stop+1});
                }
            }
        }
        if(cost[dst]==1e6) return -1;
        return cost[dst];
    }
};