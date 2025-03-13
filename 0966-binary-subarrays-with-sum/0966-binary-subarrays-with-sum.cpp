class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0,r = 0;
        int cnt  = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum>goal && l<r){
                sum -= nums[l];
                l++;
            }
            
            if(sum==goal) {
                int templ= l;
                int cntz = 0;
                while(templ<r && nums[templ]==0){
                    cntz++;
                    templ++;
                }
                
                cnt += (cntz+1);
            }
            r++;
        }
        return cnt;
    }
};