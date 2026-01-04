class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0,r=0;
        int sum = 0;
        unordered_map<int,int>mpp;
        int mini = INT_MAX;
        while(r<n){
            if(mpp.find(nums[r])==mpp.end()){
                sum += nums[r];
            }
            while(sum>=k){
                mini = min(mini,r-l+1);
                if(mpp[nums[l]]<=1){
                    sum -= nums[l];
                    mpp.erase(nums[l]);
                }else mpp[nums[l]]--;
                
                l++;
            }
            mpp[nums[r]]++;
            r++;
        }
        return mini==INT_MAX?-1:mini;
    }
};