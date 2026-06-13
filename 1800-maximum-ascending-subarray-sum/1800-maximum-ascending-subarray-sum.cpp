class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int sum = 0;
        int prev = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > prev ){
                sum += nums[i];
            }else{
                maxi = max(maxi,sum);
                sum = nums[i];
            }
            prev = nums[i];
        }
        maxi = max(maxi,sum);

        return maxi;
    }
};