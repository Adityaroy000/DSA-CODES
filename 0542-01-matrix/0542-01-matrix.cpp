class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>vis(m,(vector<int>(n,0)));
        vector<vector<int>>dist(m,(vector<int>(n,0)));

        queue<pair<pair<int,int>,int>>q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j]==0) {
                    dist[i][j] = 0;
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            int rid = it.first.first;
            int cid = it.first.second;
            int step = it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrid = rid+drow[i];
                int ncid = cid+dcol[i];

                if(nrid>=0 && nrid<m && ncid >= 0 && ncid <n && !vis[nrid][ncid] && mat[nrid][ncid]==1){
                    vis[nrid][ncid] = 1;
                    dist[nrid][ncid] = step+1;
                    q.push({{nrid,ncid},step+1});
                }
            }
        }
        return dist;
    }
};