class Solution {
public:
    int m,n;
    void dfs(int i,int j, vector<vector<int>>& vis,long long& sum, vector<vector<int>>& grid){
        vis[i][j] = 1;
        sum += grid[i][j];

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        for(int x=0;x<4;x++){
            int nrow = i+drow[x];
            int ncol = j+dcol[x];

            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && !vis[nrow][ncol] && grid[nrow][ncol]!=0){
                dfs(nrow,ncol,vis,sum,grid);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt  = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long sum = 0;
                if(!vis[i][j] && grid[i][j] != 0){
                    dfs(i,j,vis,sum,grid);
                    if(sum % k == 0) cnt++;
                }
            }
        }
        return cnt;
    }
};