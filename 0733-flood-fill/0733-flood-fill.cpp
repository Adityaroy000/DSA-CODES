class Solution {
public:
    void dfs(int sr,int sc,int drow[],int dcol[],vector<vector<int>>& ans, vector<vector<int>>& vis,int color,int oc){
        vis[sr][sc] = 1;
        ans[sr][sc] = color;
        for(int i =0;i<4;i++){
            int nrid = sr+drow[i];
            int ncid = sc+dcol[i];
            if(nrid<ans.size()&&nrid>=0&&ncid<ans[0].size()&&ncid>=0&&!vis[nrid][ncid] && ans[nrid][ncid]==oc){
                dfs(nrid,ncid,drow,dcol,ans,vis,color,oc);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(m,vector<int>(n));
        int oc = image[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(sr,sc,drow,dcol,ans,vis,color,oc);

        return ans;
    }
};