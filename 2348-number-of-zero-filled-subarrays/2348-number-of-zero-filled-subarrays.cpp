class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int i=0;
        while(i<n){
            if(nums[i]==0){
                int j = i+1;
                while(j<n && nums[j]==0) j++;
                long long len = j-i;
                long long t = 1LL*(len*(len+1))/2;
                ans += t;
                i = j;
            }else i++;
        }
        return ans;
    }
};