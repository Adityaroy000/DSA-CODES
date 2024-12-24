class Solution {
private:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>>adj(v+1);
        for(int i = 1; i<=v; i++){
            for(int j = 1;j<=v;j++){
                if(isConnected[i-1][j-1]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>visited(v+1,0);
        int cnt = 0;
        for(int i =1; i<=v; i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                cnt++;
            }
        }
        return cnt;
    }
};