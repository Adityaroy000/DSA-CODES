class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int r0=-1,c0=-1;
        vector<pair<int,int>> id;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        for(int i=0; i<r; i++){
            for(int j = 0; j<c; j++){
                if(matrix[i][j]==0){
                    id.push_back({i,j});
                    r0 = i;
                    c0 = j;
                    vis[r0][c0] = 1;
                }
            }
        }
        if(r0 == -1 && c0 == -1) return;
        for(auto it : id){
            int rowid = it.first;
            int colid = it.second;
            for(int j = 0; j<c; j++){
                if(vis[rowid][j]!=1){
                    matrix[rowid][j] = 0;
                    vis[rowid][j] = 1;
                }
            }
            for(int i = 0; i<r; i++){
                if(vis[i][colid]!=1){
                    matrix[i][colid] = 0;
                    vis[i][colid] = 1;
                }
            }
        }
    }
};