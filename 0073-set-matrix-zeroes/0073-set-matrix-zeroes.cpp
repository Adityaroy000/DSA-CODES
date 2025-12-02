class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<pair<int,int>>idx;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    idx.push_back({i,j});
                }
            }
        } 

        for(int i=0;i<idx.size();i++){
            int row = idx[i].first;
            int col = idx[i].second;

            for(int j = 0;j<n;j++){
                matrix[row][j] = 0;
            }
            for(int j=0;j<m;j++){
                matrix[j][col] = 0;
            }
        }  
    }
};