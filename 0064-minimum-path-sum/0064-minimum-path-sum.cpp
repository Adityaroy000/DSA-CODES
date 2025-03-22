class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n,-1));
        for(int i = 0;i<m ;i++){
            for(int j =0;j<n; j++){
                if(i==0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    long long upsum =1e9 , leftsum = 1e9;
                    if(i>0) upsum = grid[i][j] +dp[i-1][j];
                    if(j>0) leftsum = grid[i][j] +dp[i][j-1];
                    
                    dp[i][j] = min(upsum,leftsum);
                }
            }
        }
        return dp[m-1][n-1];
    }
};