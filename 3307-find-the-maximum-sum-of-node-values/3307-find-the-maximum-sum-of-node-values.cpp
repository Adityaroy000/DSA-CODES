class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        int e = edges.size();

        int nuksan = INT_MAX;
        int cnt =0;

        long long sum = 0;

        for(int i=0;i<n;i++){
            if((nums[i]^k) > nums[i]){
                cnt++;
                sum += (long long)(nums[i]^k);
            }else{
                sum +=(long long)nums[i];
            }
            nuksan = min(nuksan,abs(nums[i]-(nums[i]^k)));
        }

        if(cnt%2 != 0){
            return sum-(long long)nuksan;
        }

        return sum;
    }
};