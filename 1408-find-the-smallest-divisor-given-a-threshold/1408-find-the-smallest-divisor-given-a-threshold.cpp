class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt = 0;
            for(int i = 0; i<n; i++){
                if(nums[i]%mid == 0) cnt += (nums[i]/mid);
                else cnt += (nums[i]/mid)+1;
            }
            if(cnt <= threshold){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};