class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int l=0, r=n-1;
        while(l<=r){
            while(l<=r && nums[l] != val) l++;

            while(l<=r && nums[r]== val) r--;

            if(l<=r) swap(nums[l],nums[r]);
        }    

        return r+1;
    }
};