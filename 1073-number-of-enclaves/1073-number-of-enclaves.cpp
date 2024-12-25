class Solution {
private:
    void bfs(vector<vector<int>>& vis,vector<vector<int>>& grid,queue<pair<int,int>>q){
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int rid = q.front().first;
            int cid = q.front().second;
            q.pop();
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
        queue<pair<int,int>>q;
        //boundary check
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                //first row,first col,last row,last col
                if(i==0 || j==0|| i==r-1||j==c-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        bfs(vis,grid,q);
        int count = 0;
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(grid[i][j]==1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};