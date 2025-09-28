class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        
        sort(nums.begin(),nums.end());
        int l=0,r=0;
        while(r<n){
            while(nums[r]-nums[l]>1) l++;
            if(nums[r]-nums[l] == 1){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
};