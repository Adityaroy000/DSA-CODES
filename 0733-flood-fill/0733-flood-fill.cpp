class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        vector<vector<int>>ans;
        vis[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int rid = q.front().first;
            int cid = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = rid+drow[i];
                int ncol = cid+dcol[i];
                if(ncol<c&&ncol>=0&&nrow<r&&nrow>=0&&vis[nrow][ncol]!=color&&image[sr][sc]==image[nrow][ncol]){
                    vis[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i = 0; i<r; i++){
            for(int j = 0;j<c; j++){
                if(vis[i][j]!=color){
                    vis[i][j] = image[i][j];
                }
            }
        }
        return vis;
    }
};