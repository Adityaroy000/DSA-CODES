class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorr = 0;
        int n = nums.size();
        int sum=0,arrsum=0;
        for(int i = 1;i<=n; i++){
            sum += i;
        }
        for(int i = 0; i<n; i++){
            arrsum = arrsum + nums[i];
        }
        return sum-arrsum;
    }
};