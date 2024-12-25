class Solution {
private:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int drow[],int dcol[],int& cnt){
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int rid = q.front().first;
            int cid = q.front().second;
            q.pop();
            cnt++;
            for(int i = 0; i<4; i++){
                int nrow = rid+drow[i];
                int ncol = cid+dcol[i];
                if(nrow<grid.size() && nrow>=0 && ncol<grid[0].size() && ncol>=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int cnt = 0;
        int count = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]==1) count++;
            }
        }
        for(int j = 0; j<c; j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                bfs(0,j,vis,grid,drow,dcol,cnt);
            }
            if(grid[r-1][j]==1 && vis[r-1][j]==0){
                bfs(r-1,j,vis,grid,drow,dcol,cnt);
            }
        }
        for(int i = 0; i<r; i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                bfs(i,0,vis,grid,drow,dcol,cnt);
            }
            if(grid[i][c-1]==1 && vis[i][c-1]==0){
                bfs(i,c-1,vis,grid,drow,dcol,cnt);
            }
        }
        return (count-cnt);
    }
};