class NumMatrix {
public:
    vector<vector<int>>pre;  
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        pre.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j] = pre[i][j-1]+pre[i-1][j]-pre[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ta = pre[row2+1][col2+1];
        int la = pre[row2+1][col1];
        int topa = pre[row1][col2+1];
        int ca = pre[row1][col1];

        int ans = ta-(la+topa-ca);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */