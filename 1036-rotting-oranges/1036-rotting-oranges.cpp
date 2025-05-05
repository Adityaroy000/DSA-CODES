class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        int maxtime = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int t = it.second;
            maxtime = max(maxtime,t);
            int rid = it.first.first;
            int cid = it.first.second;
            for(int i = 0;i<4;i++){
                int nrid = rid+drow[i];
                int ncid = cid+dcol[i];
                if(nrid<m&&nrid>=0&&ncid<n&&ncid>=0&&grid[nrid][ncid]==1&&vis[nrid][ncid]!=2){
                    vis[nrid][ncid]=2;
                    q.push({{nrid,ncid},t+1});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return maxtime;
    }
};