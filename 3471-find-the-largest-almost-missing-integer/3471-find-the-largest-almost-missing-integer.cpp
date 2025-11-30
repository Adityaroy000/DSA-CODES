class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;

        int l=0,r=0;
        while(r<n){
            if(r-l+1 > k){
                l++;
                for(int i=l;i<=r;i++){
                    mpp[nums[i]]++;
                }
            }else{
                mpp[nums[r]]++;
            }
            r++;
        }
        int maxi = INT_MIN;
        for(auto &it: mpp){
            if(it.second==1){
                maxi = max(maxi,it.first);
            }
        }
        if(k == n) return *max_element(nums.begin(),nums.end());
        return maxi==INT_MIN?-1:maxi;
    }
};