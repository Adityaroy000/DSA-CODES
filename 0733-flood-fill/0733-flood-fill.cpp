class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(m,vector<int>(n));
        int oc = image[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        while(!q.empty()){
            auto it = q.front();
            int rid = it.first;
            int cid = it.second;
            q.pop();
            for(int i =0;i<4;i++){
                int nrid = rid+drow[i];
                int ncid = cid+dcol[i];
                 if(nrid<m&&nrid>=0&&ncid<n&&ncid>=0&&image[nrid][ncid]==oc&&vis[nrid][ncid]==0){
                    vis[nrid][ncid]=1;
                    q.push({nrid,ncid});
                    ans[nrid][ncid] = color;
                }
            }
        }
        return ans;
    }
};