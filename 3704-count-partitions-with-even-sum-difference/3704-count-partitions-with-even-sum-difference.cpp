class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }
        int s=0,cnt = 0;
        for(int i = 0;i<n-1; i++){
            s += nums[i];
            sum = sum-nums[i];
            int sub = s-sum;
            if(sub % 2==0){
                cnt++;
            }
        }
        return cnt;
    }
};