class Solution {
private:
    int atmostk(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int>mpp;
        int l=0,r=0,cnt = 0;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size()<=k){
                cnt += (r-l+1);
            }
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int atmk = atmostk(nums,k);
        int atmkm1 = atmostk(nums,k-1);
        int cnt  = atmk-atmkm1;
        return cnt;
    }
};