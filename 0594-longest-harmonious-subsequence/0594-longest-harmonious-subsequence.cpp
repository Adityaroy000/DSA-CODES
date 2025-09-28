class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        unordered_map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(int i:nums){
            mpp[i]++;
        }

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] == 1){
                int c1 = mpp[nums[i]];
                int c2 = mpp[nums[i-1]];
                maxlen = max(maxlen,c1+c2);
            }
        }
        return maxlen;
        
    }
};