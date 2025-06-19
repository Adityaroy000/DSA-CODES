class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int i=0,j=1,cnt=0;
        int mini = nums[i];
        int maxi = nums[j];

        while(i<n && j<n){
            if(maxi-mini <= k){
                j++;
                if(j<n) maxi = nums[j];
            }else{
                cnt++;
                mini = nums[j];
                i=j;
                j++;
                if(j<n) maxi =nums[j];
            }
        }
        cnt++;

        return cnt;
    }
};