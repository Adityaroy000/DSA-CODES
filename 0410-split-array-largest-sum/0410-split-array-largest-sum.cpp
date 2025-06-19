class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum = 0,cnt = 0;
            bool valid = true;
            for(int i=0;i<n;i++){
                if(nums[i]>mid) {
                    valid = false;
                    break;
                }
                sum+=nums[i];
                if(sum > mid){
                    cnt++;
                    sum = nums[i];
                    if(cnt+1 > k) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) cnt++;
            if(valid && cnt<=k){
                ans = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};