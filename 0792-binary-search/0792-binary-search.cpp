class Solution {
public:
    int bs(vector<int>& nums, int target,int low,int high){
        int mid = (low+high)/2;
        if(low>high) return -1;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return bs(nums,target,mid+1,high);
        else return bs(nums,target,low,mid-1);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bs(nums,target,0,n-1);
    }
};