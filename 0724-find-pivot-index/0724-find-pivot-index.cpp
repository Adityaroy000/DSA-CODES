class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>psum(n),ssum(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            psum[i] = sum;
        }
        sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += nums[i];
            ssum[i] = sum;
        }

        for(int i=0;i<n;i++){
            int leftsum = 0;
            if(i>0) leftsum = psum[i-1];
            int rightsum = 0;
            if(i<n-1) rightsum = ssum[i+1];
            if(leftsum == rightsum) return i;
        }
        return -1;
    }
};