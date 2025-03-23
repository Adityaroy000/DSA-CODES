class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = m-1;i>=0; i--){
            int s = triangle[i].size();
            for(int j = s-1;j>=0; j--){
                if(i== m-1) dp[i][j] = triangle[i][j];
                else{
                    int up = triangle[i][j] + dp[i+1][j];
                    int diag = triangle[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(up,diag);
                }
            }
        }

        return dp[0][0];
    }
};