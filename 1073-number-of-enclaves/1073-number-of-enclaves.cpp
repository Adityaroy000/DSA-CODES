class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        vis[row][col] = true;

        for(int i=0;i<4;i++){
            int nrid = row+drow[i];
            int ncid = col+dcol[i];

            if(nrid<0 || ncid<0 || nrid>=grid.size() || ncid>=grid[0].size()) continue;

            if(grid[nrid][ncid]==1 && !vis[nrid][ncid]){
                dfs(nrid,ncid,grid,vis);
            }
        }

}
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1) && grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==false) cnt++;
            }
        }
        return cnt;
    }
};