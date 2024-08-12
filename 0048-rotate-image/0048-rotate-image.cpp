class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> m2(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                m2[i][j]=matrix[n-1-j][i];
            }
        }
        matrix = m2;
    }
};