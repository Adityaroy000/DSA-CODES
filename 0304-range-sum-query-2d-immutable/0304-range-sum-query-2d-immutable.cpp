class NumMatrix {
public:
    vector<vector<int>>psum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            vector<int>p;
            int sum = 0;
            for(int j=0;j<m;j++){
                sum += matrix[i][j];
                p.push_back(sum);
            }
            psum.push_back(p);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++){
            if(col1>0){
                sum += psum[i][col2]-psum[i][col1-1];
            }else{
                sum += psum[i][col2];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */