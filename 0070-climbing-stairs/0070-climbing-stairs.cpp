class Solution {
public:
    int cs(int n ,vector<int> &dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = cs(n-1,dp)+cs(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return cs(n,dp);
    }
};