class Solution {
public:
    int bfs(int node,int n,vector<vector<pair<int,int>>>& adj){
        queue<pair<int,int>>q;
        q.push({node,0});

        vector<int>timeReq(n+1,1e9);
        timeReq[node] = 0;

        while(!q.empty()){
            int currnode = q.front().first;
            int currnodetime = q.front().second;
            q.pop();

            for(auto it:adj[currnode]){
                int adjnode = it.first;
                int time = it.second;
                
                if(timeReq[adjnode] > time+currnodetime){
                    timeReq[adjnode] = time+currnodetime;
                    q.push({adjnode,time+currnodetime});
                }
            }
        }
        vector<int>temp;
        for(int i=0;i<timeReq.size();i++){
            if(timeReq[i]!=1e9){
                temp.push_back(timeReq[i]);
            }
        }
        int ans = *max_element(temp.begin(),temp.end());
        if(ans==0 || temp.size()!=n) return -1;
        else return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int time = times[i][2];

            adj[u].push_back({v,time});
        }


        int ans = bfs(k,n,adj);
        return ans;

    }
};