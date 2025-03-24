class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(j<0 || j>=matrix.size()) return 1e9;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int up = matrix[i][j] + helper(i-1,j,matrix,dp);
        int rdiag = matrix[i][j] + helper(i-1,j+1,matrix,dp);
        int ldiag = matrix[i][j] + helper(i-1,j-1,matrix,dp);

        return dp[i][j] = min(up,min(rdiag,ldiag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        for(int i = 0;i<n;i++){
            ans = min(ans,helper(n-1,i,matrix,dp));
        }
        
        return ans;

    }
};