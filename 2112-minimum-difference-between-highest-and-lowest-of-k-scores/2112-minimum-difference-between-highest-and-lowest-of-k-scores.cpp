class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = INT_MAX;

        sort(nums.begin(),nums.end());

        int l = 0,r =k-1;
        while(r<n){
            mini = min(mini,nums[r]-nums[l]);
            l++;
            r++;
        }

        return mini;
    }
};