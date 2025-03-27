class Solution {
public:
    bool helper(int i,int sum,int ts,vector<int>& nums,vector<vector<int>>&dp){
        if(sum == ts) return true;
        if(i == 0){
            if(sum+nums[i] == ts) return true;
            else return false;
        }
        if(sum>ts) return false;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool take = helper(i-1,sum+nums[i],ts,nums,dp);
        if(take) return true;
        bool nottake = helper(i-1,sum,ts,nums,dp);
        return dp[i][sum] = take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        if(sum%2 != 0) return false;

        return helper(n-1,0,sum/2,nums,dp);
    }
};