class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0,high = n-1;
        if(nums[low]<nums[high]) return nums[low];
        int ans = INT_MAX;

        while(low<=high){
            int mid = (high+low)/2;
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);
                low = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};