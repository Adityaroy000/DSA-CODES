class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = INT_MAX;

        for(int i=l;i<=r;i++){
            int sum = 0;
            int s=0,e=0;
            while(e<n){
                sum += nums[e];
                if(e-s+1 == i){
                    if(sum>0){
                        minsum = min(minsum,sum);
                    }
                    sum -= nums[s];
                    s++;
                }
                e++;
            }
        }
        
        return minsum == INT_MAX?-1:minsum;
    }
};