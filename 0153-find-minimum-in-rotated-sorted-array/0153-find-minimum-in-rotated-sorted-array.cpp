class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        if(nums[low]<=nums[high]) return nums[low];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(high==(low+1)) {
                if(nums[low]<=nums[high]) return nums[low];
                else return nums[high];
            }
            else if(nums[low]<=nums[mid]) low=mid;
            else high=mid;
        }
        return 0;
    }
};