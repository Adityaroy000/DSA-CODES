class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxlen = 0;

        int l=0,r=0;
        while(r<n){
            if(nums[l]%2!=0){
                l++;
            }
            if(l<=r && r>0 && nums[r]%2 == nums[r-1]%2){
                maxlen = max(maxlen,r-l);
                l=r;
            }
            if(l<=r && nums[r]>threshold){
                maxlen = max(maxlen,r-l);
                l=r+1;
            }
            r++;
        }
        maxlen = max(maxlen,r-l);
        return maxlen;
    }
};