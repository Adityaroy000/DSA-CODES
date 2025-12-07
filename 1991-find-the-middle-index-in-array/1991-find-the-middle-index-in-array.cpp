class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int sum = accumulate(nums.begin(),nums.end(),0);

        vector<int>psum(n+1);
        for(int i=1;i<=n;i++){
            psum[i] = psum[i-1]+nums[i-1];
        }
        
        for(int i=0;i<n;i++){
            int ssum = sum-psum[i]-nums[i];
            if(ssum == psum[i]){
                return i;
            }
        }
        return -1;
    }
};