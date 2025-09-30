class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minlen = INT_MAX;
        int n = nums.size();
        
        for(int l=0;l<n;l++){
            int res = 0;
            for(int r=l;r<n;r++){
                res |= nums[r];
                if(res>=k){
                    minlen = min(minlen,r-l+1);
                    break;
                }
            }
        }
        return minlen==INT_MAX?-1:minlen;
    }
};