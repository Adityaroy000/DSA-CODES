class Solution {
public:
    void bfs(int n,vector<int>& vis,vector<int> adj[]){
        queue<int>q;
        q.push(n);
        while(!q.empty()){
            int node = q.front();
            vis[node] = 1;
            q.pop();
            for(auto &it:adj[node]){
                if(!vis[it])
                    q.push(it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(i!=j && isConnected[i][j]==1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n,0);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                bfs(i,vis,adj);
            }
        }
        return cnt;
    }
};