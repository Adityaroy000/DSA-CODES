class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0,high = n-1;
        if(nums[low]<nums[high]) return nums[low];
        int mini = -1;
        while(low<high){
            int mid = (high+low)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }else{
                high = mid;
            }

        }
        return nums[low];
    }
};