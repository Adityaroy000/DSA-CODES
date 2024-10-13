class Solution {
public:
int first(vector<int>& nums,int target){
    int n = nums.size();
    int low = 0,high = n-1;
    int first = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            first = mid;
            high = mid-1;
        }
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return first;
}
int last(vector<int>& nums,int target){
    int n = nums.size();
    int low = 0,high = n-1;
    int last = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            last = mid;
            low = mid+1;
        }
        else if(nums[mid]<target) low = mid+1;
        else high = mid-1;
    }
    return last;
}
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int target = nums[mid];
            int f = first(nums,target);
            int l = last(nums,target);
            if(f == l) return nums[f];
            else if(f%2==0) low = mid+1;
            else if(f%2!=0) high = mid-1;
        }
        return -1;
    }
};