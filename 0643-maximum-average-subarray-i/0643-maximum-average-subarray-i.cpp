class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double sum = 0;
        int l=0,r=0;
        double maxavg = INT_MIN;
        while(r<n){
            sum += nums[r];
            if(r-l+1 == k) {
                double avg = sum/k;
                maxavg = max(maxavg,avg);
            }
            while(r-l+1 >=k ){
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return maxavg;
    }
};