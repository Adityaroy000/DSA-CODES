class Solution {
private:
    void dfs(int node,vector<vector<int>>& isConnected,vector<int>& visited){
        visited[node] = 1;
        int v = isConnected.size();
        for(int i = 1; i<=v; i++){
            if(isConnected[node-1][i-1]==1 && !visited[i]){
                dfs(i,isConnected,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>visited(v+1,0);
        int cnt = 0;
        for(int i =1; i<=v; i++){
            if(!visited[i]){
                dfs(i,isConnected,visited);
                cnt++;
            }
        }
        return cnt;
    }
};