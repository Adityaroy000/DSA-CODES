class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pre(n,0);
        vector<int>mini(n+1);
        mini[n] = nums[n-1];
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            pre[i] = sum;
        }

        for(int i=n-1;i>=0;i--){
            mini[i] = min(mini[i+1],nums[i]);
        }  
        long long ans = LLONG_MIN;
        for(int i=0;i<n-1;i++){
            long long score = pre[i]-mini[i+1];
            ans = max(ans,score);
        }      
        return ans;
    }
};