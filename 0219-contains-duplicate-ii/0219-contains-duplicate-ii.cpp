class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;

        int l=0,r=0;
        while(r<n){
            mpp[nums[r]]++;
            if(r-l <= k && l!=r && mpp[nums[r]]>1){
                return true;
            }
            if(r-l>k){
                mpp[nums[l]] == 1?mpp.erase(nums[l]):mpp[nums[l]]--;
                l++;
                if(mpp[nums[r]]>1) return true;
            }
            
            r++;
        }
        return false;
    }
};