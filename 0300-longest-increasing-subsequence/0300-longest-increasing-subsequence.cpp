class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);

        int i=1;
        while(i<n){
            int j=0;
            while(j<i){
                if(nums[i]>nums[j]){
                    int len = 1+dp[j];
                    dp[i] = max(dp[i],len);
                }
                j++;
            }
            i++;
        }

        return *max_element(dp.begin(),dp.end());
    }
};