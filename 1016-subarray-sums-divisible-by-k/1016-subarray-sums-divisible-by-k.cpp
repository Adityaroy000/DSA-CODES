class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int cnt = 0;
        int sum = 0;
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int mod = (sum%k+k)%k;

            if(mpp.find(mod)!=mpp.end()){
                cnt += mpp[mod];
            }
            mpp[mod]++;
        }
        return cnt;
    }
};