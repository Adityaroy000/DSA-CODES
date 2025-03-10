class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0,high = n-1;
        int start = -1,end = -1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target){
                start = mid;
                high = mid-1;
            }else if(nums[mid]<target){
                low = mid+1;
            }else high = mid-1;
        }
        low = 0,high = n-1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]==target){
                end = mid;
                low = mid+1;
            }else if(nums[mid]<target){
                low = mid+1;
            }else high = mid-1;
        }
        return {start,end};
    }
};