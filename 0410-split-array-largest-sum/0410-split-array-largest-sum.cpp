class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            int currsum = 0,reqarr = 1;
            for(int j = 0; j<n; j++){
                if((currsum+nums[j])<=mid){
                    currsum+=nums[j];
                }else{
                    reqarr++;
                    currsum = nums[j];
                    if(currsum>mid) break;
                }
            }
            if(reqarr<=k){
                ans = mid;
                high = mid-1;
            } else low = mid+1;
        }
        return ans;
    }
};