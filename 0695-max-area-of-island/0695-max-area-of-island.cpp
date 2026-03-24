class Solution {
public:
    int m,n;
    vector<vector<int>>vis;
    int bfs(int r, int c, vector<vector<int>>& grid){
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c] = 1;
        int cnt = 0;
        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            cnt++;

            for(int i=0;i<4;i++){
                int nr = row+drow[i];
                int nc = col+dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m,vector<int>(n,0));

        int maxi = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int temp = bfs(i,j,grid);
                    maxi = max(maxi,temp);
                }
            }
        }
        return maxi;
    }
};