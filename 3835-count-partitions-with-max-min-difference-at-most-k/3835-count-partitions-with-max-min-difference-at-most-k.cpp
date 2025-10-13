class Solution {
public:
    int MOD = 1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>max_dq;
        deque<int>min_dq;
        vector<long long>dp(n+1);
        vector<long long>s(n+2);
        dp[0] = 1;
        s[0] = 0;
        s[1] = 1;

        int left_ptr = 0;

        for(int i=1;i<=n;i++){
            while(!max_dq.empty() && nums[max_dq.back()]<=nums[i-1]) max_dq.pop_back();
            max_dq.push_back(i-1);
            while(!min_dq.empty() && nums[min_dq.back()]>=nums[i-1]) min_dq.pop_back();
            min_dq.push_back(i-1);

            while(nums[max_dq.front()] - nums[min_dq.front()] > k){
                if(left_ptr == max_dq.front()) max_dq.pop_front();
                if (left_ptr == min_dq.front()) min_dq.pop_front();
                left_ptr++;
            }

            dp[i] = (s[i]-s[left_ptr] + MOD)%MOD;
            s[i+1] = (s[i]+dp[i])%MOD;
        }
        return dp[n];
    }
};