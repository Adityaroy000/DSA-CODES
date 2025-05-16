class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<vector<int>>q;
        bool vis[41][41][1601];
        memset(vis,false,sizeof(vis));
        q.push({0,0,k});
        vis[0][0][k] = true;

        int steps = 0;
        
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto it = q.front();
                q.pop();
                int rid = it[0];
                int cid = it[1];
                int obs = it[2];

                if(rid == m-1 && cid == n-1) return steps;
                for(int i=0;i<4;i++){
                    int nrid = rid+drow[i];
                    int ncid = cid+dcol[i];

                    if(nrid>=0 && nrid<m && ncid<n && ncid>=0){
                        if(grid[nrid][ncid]==0 && !vis[nrid][ncid][obs]){
                            q.push({nrid,ncid,obs});
                            vis[nrid][ncid][obs] = true;
                        }else if(grid[nrid][ncid]==1 && obs>0 && !vis[nrid][ncid][obs-1]) {
                            q.push({nrid,ncid,obs-1});
                            vis[nrid][ncid][obs-1] = 1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};