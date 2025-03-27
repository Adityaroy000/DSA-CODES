class Solution {
public:
    bool helper(int i,int target,vector<int>& arr, vector<vector<int>>& dp){
        if(target <0) return false;
        if(target == 0) return true;
        if(i == 0){
            if(target-arr[0] == 0) return true;
            else return false;
        }
        
        if(dp[i][target] != -1) return dp[i][target];
        
        bool take = helper(i-1,target-arr[i],arr,dp);
        if(take) return true;
        bool nottake = helper(i-1,target,arr,dp);
        return dp[i][target] = take || nottake;
    } 
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 != 0) return false;
        int ts = sum/2;
        vector<vector<int>>dp(n,vector<int>(ts+1,-1));

        
        return helper(n-1,ts,nums,dp);
    }
};