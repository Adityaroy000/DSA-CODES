class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        long long cnt = 0,count=0;
        int r = 0,l =0;
        while(r<n){
            if(nums[r]==maxi){
                count++;
            }
            while(count==k){
                if(nums[l]==maxi) count--;
                l++;
            }
            cnt += l;
            r++;
        }
        return cnt;
    }
};