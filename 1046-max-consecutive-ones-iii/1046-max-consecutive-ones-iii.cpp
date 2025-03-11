class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0,r = 0;
        int maxlen  = 0,len = 0,cntz = 0;
        while(r<n){
            if(nums[r]==0) cntz++;
            if(cntz>k){
                if(nums[l]==0) {
                    cntz--;
                }
                l++;
            } 
            if(cntz<=k){
                len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};