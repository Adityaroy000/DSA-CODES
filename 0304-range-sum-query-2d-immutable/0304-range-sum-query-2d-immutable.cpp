class NumMatrix {
public:
    vector<vector<int>>psum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        psum.resize(n,vector<int>(m));
        int sum = 0;
        for(int i=0;i<m;i++){
            sum += matrix[0][i];
            psum[0][i] = sum;
        }
        for(int i=1;i<n;i++){
            psum[i][0] = psum[i-1][0]+matrix[i][0];
        }
        sum = 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                psum[i][j] = matrix[i][j]+psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(col1 == 0 && row1 == 0){
           return psum[row2][col2];
        }else if(row1 == 0){
            return psum[row2][col2] - psum[row2][col1-1];
        }else if(col1==0){
           return psum[row2][col2]-psum[row1-1][col2];
        }

        int sum = psum[row2][col2]-psum[row2][col1-1]-psum[row1-1][col2]+psum[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */