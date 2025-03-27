class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2 != 0) return false;
        int ts = sum/2;
        vector<vector<bool>>dp(n,vector<bool>(ts+1,false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=ts){
            dp[0][arr[0]] = true;
        }
        //Fill dp table
        for(int i=1;i<n;i++){
            for(int j=1;j<=ts;j++){//j->target
                bool nottake = dp[i-1][j];
                bool take = false;
                if(arr[i]<=j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take||nottake;
            }
        }
        return dp[n-1][ts];
    }
};