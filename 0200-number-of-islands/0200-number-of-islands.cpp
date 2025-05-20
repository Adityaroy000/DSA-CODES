class Solution {
public:
    int m,n;
    void dfs(int row,int col, vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[row][col] = 1;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrid = row+drow[i];
            int ncid = col+dcol[i];

            if(nrid>=0 && nrid<m && ncid<n && ncid>=0 && vis[nrid][ncid]==0 && grid[nrid][ncid]=='1'){
                dfs(nrid,ncid,vis,grid);
            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};