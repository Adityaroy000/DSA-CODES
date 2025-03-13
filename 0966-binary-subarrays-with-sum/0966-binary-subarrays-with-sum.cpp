class Solution {
private:
    int sumlessg(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0,r = 0;
        int cnt  = 0,sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum > goal && l<r){
                sum -= nums[l];
                l++;
            }
            if(sum <=goal){
                cnt = cnt+(r-l+1);
            }
            r++;
        }
        return cnt ;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        //no of subarray with sum <= goal
        int sltg = sumlessg(nums,goal);
        //no of subarray with sum <= goal-1
        int sltgm1 = sumlessg(nums,goal-1);
        //subtracting both will give us the sum == goal 
        int cnt = sltg - sltgm1;
        return cnt;
    }
};