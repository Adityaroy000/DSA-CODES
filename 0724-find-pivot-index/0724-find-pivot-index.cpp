class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>psum(n+1,0),ssum(n+1,0);

        for(int i=0;i<n;i++){
            psum[i+1] = psum[i]+nums[i];
        }

        for(int i = n-1;i>=0 ;i--){
            ssum[i] = ssum[i+1]+nums[i];
        }

        for(int i=0;i<n;i++){
            int left = psum[i];
            int right = ssum[i+1];

            if(left == right){
                return i;
            }
        }
        return -1;
    }
};