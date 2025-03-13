class Solution {
private:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=0,cnt=0;
        int odd = 0;
        while(r<n){
            if(nums[r]%2!=0){
                odd++;
            }
            while(odd>k){
                if(nums[l]%2!=0){
                    odd--;
                }
                l++;
            }
            if(odd <= k){
                cnt += (r-l+1);
            }
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int atmostk = atmost(nums,k);
        int atmostkm1 = atmost(nums,k-1);
        
        return atmostk - atmostkm1;
    }
};