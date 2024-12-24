class Solution {
private:
    void dfs(int sr,int sc ,vector<vector<int>>& ans,vector<vector<int>>& image,int drow[], int dcol[],int color,int iniColor){
        int r = image.size();
        int c = image[0].size();
        ans[sr][sc]=color;
        for(int i = 0; i<4; i++){
            int nrow = sr+drow[i];
            int ncol = sc+dcol[i];
            if(ncol<c&&ncol>=0&&nrow<r&&nrow>=0&&ans[nrow][ncol]!=color&&iniColor==image[nrow][ncol]){
                dfs(nrow,ncol,ans,image,drow,dcol,color,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int iniColor = ans[sr][sc];
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,drow,dcol,color,iniColor);
        return ans;
    }
};