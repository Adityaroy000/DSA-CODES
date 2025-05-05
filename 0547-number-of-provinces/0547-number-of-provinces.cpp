class Solution {
public:
    void bfs(int n,vector<int>& vis,vector<vector<int>>& isConnected){
        queue<int>q;
        q.push(n);
        vis[n] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0;i<isConnected.size();i++){
                if(isConnected[node][i]==1 && !vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int>vis(n,0);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                bfs(i,vis,isConnected);
            }
        }
        return cnt;
    }
};