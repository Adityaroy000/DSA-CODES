class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        for(int i =0;i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i = 1;i<n; i++){
            for(int j = 0;j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int rdiag = 1e9,ldiag = 1e9;
                if(j+1 < n) rdiag = matrix[i][j] + dp[i-1][j+1];
                if(j-1 >= 0) ldiag = matrix[i][j] + dp[i-1][j-1];
                dp[i][j] = min(up,min(rdiag,ldiag));
            }
        }
        int mini = dp[n-1][0];
        for(int i = 0;i<n; i++){
            if(mini > dp[n-1][i]){
                mini = dp[n-1][i];
            }
        }
        return mini;
    }
};