class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0]==1  || grid[n-1][n-1]==1) return -1;

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        vector<vector<int>>vis(n,vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            int rid = it.first.first;
            int cid = it.first.second;
            int len = it.second;
            q.pop();

            if(rid == n-1 && cid == n-1) return len;

            for(int i=0;i<8;i++){
                int nrid = rid+drow[i];
                int ncid = cid+dcol[i];

                if(nrid<n && nrid>=0 && ncid<n && ncid>=0 && vis[nrid][ncid]==0 && grid[nrid][ncid]==0){
                    q.push({{nrid,ncid},len+1});
                    vis[nrid][ncid] = 1;
                }
            }
        }

        return -1;
    }
};