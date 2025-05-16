class Solution {
public:
    int n;
    int maxlen = 0;
    int seq(int prev,int i,vector<int>& nums, vector<vector<int>>& dp){
        if(i==n){
            return 0;
        }

        if(dp[prev+1][i]!= -1) return dp[prev+1][i];

        int take = 0;
        if(prev == -1 || nums[i]>nums[prev]){
            take = 1+seq(i,i+1,nums,dp);
        }
        int nottake = seq(prev,i+1,nums,dp);
        return dp[prev+1][i] = max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n,-1));
        return seq(-1,0,nums,dp);
    }
};