class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>ans(r,vector<int>(c,0));
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int rid = q.front().first.first;
            int cid = q.front().first.second;
            int d = q.front().second;
            q.pop();
            ans[rid][cid] = d;
            for(int i = 0;i<4;i++){
                int nrow = rid+drow[i];
                int ncol = cid+dcol[i];
                if(nrow<r && nrow>=0 && ncol<c &&ncol>=0 && mat[nrow][ncol]==1 &&vis[nrow][ncol]!=1){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},d+1});
                }
            }
        }
        return ans;
    }
};