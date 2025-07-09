class Solution {
public:
    void dfs(int node, vector<vector<int>>& stones,vector<int>& vis){
        vis[node] = 1;
        int row = stones[node][0];
        int col = stones[node][1];

        for(int i=0;i<stones.size();i++){

            if(!vis[i]){
                if(stones[i][0] == row || stones[i][1] == col){
                    dfs(i,stones,vis);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n,0);
        int cnt  = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,stones,vis);
            }
        }
        return n-cnt;
    }
};