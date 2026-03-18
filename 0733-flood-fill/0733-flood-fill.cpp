class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int pc = image[sr][sc];
        if(pc == color) return image;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<int,int>>q;
        q.push({sr,sc});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            image[r][c] = color;

            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==pc){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};