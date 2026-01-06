class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        mini[n-1] = nums[n-1];
        long long pre = 0;
        for(int i=n-2;i>=0;i--){
            mini[i] = min(mini[i+1],nums[i]);
        }  
        long long ans = LLONG_MIN;
        for(int i=0;i<n-1;i++){
            pre += nums[i];
            long long score = pre-mini[i+1];
            ans = max(ans,score);
        }      
        return ans;
    }
};