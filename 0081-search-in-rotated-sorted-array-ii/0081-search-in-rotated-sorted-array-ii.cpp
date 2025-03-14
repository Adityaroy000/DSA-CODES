class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0,high = n-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target) return true;
            else if(nums[low]==nums[high]){
                if(nums[low]==target) return true;
                low++;
                high--;
            }
            else if(nums[mid]>=nums[low]){
                if(target<=nums[mid]&&target>=nums[low]) high = mid-1;
                else low = mid+1;
            }else{
                if(target<=nums[high]&&target>=nums[mid]) low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};