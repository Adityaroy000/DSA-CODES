class Solution {
public:
    int rec(vector<int>&nums,int idx,vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx<0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = nums[idx] + rec(nums,idx-2,dp);
        int notpick = 0 + rec(nums,idx-1,dp);
        return dp[idx] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int maxi = rec(nums,n-1,dp);
        return maxi;
    }
};