class Solution {
public:
//here, single element will always present at even idx so, there is a pattern : in left search space of single element, the equal ele are in the form (even,odd) indexs and to right of single ele , ele are in (odd,even) indexs.
//(mid%2==0)&&nums[mid]==nums[mid+1] -> this condition means we have a ele at even, if we get same ele ahead of nums[mid] means at odd index then we will have (even,odd) that means we are left of single element... so low = mid+1
//(mid%2!=0)&&nums[mid]==nums[mid-1] -> this means we have a ele at odd index and if we get a same ele at left of it (that means at even index)then we will have (even,odd) then again we are in left of single element... so low = mid+1;
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low = 1,high = n-2;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            if((mid%2==0)&&nums[mid]==nums[mid+1] || (mid%2!=0)&&nums[mid]==nums[mid-1]) low = mid+1;
            else high =  mid-1;
        }
        return -1;
    }
};