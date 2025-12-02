class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int sum = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
            int req = sum-k;
            cnt += mpp[req];
            mpp[sum]++;
        }
        return cnt;
    }
};