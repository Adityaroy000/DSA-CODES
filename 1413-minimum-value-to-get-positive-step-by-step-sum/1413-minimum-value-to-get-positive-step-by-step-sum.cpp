class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>psum(n);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            psum[i] = sum;
        }

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            if(mini>psum[i]) mini = psum[i];
        }
        if(mini > 0){
            return 1;
        }
        int val = abs(mini);
        return val+1;
    }
};