class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int sum = 0,cnt = 0;
        mpp[0] = 1;
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            int rem = sum-goal;
            if(mpp.find(rem)!=mpp.end()){
                cnt += mpp[rem];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};