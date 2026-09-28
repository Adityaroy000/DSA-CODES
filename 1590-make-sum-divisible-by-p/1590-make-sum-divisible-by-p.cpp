class Solution {
public:
    int solve(vector<int>& nums, int k, int p){
        int n = nums.size();

        unordered_map<int,int>mpp;
        mpp[0] = -1;

        long long psum = 0;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            psum += nums[i];
            int rem = psum % p;
            int req = (rem - k + p) % p;
            if(mpp.count(req)){
                ans = min(ans, i-mpp[req]);
            }
            mpp[rem] = i;
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        vector<long long>psum(n+1,0);

        for(int i=1;i<=n;i++){
            psum[i] = nums[i-1]+psum[i-1];
        }

        int k = psum[n]%p;

        if(k == 0) return 0;

        int len = solve(nums,k,p);
        if (len == n) return -1;
        return len;
    }
};