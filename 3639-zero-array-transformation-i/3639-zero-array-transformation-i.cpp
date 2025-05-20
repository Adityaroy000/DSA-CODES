class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int>zeroarr(n,0);
        for(auto & it: queries){
            int start = it[0];
            int end = it[1];
            
            zeroarr[start] += 1;
            if(end+1<n) zeroarr[end+1] -= 1;
        }

        vector<int>res(n,0);
        int cumsum = 0;
        for(int i =0;i<n;i++){
            cumsum += zeroarr[i];
            res[i] = cumsum;
        }

        for(int i=0;i<n;i++){
            if(nums[i]-res[i] > 0) {
                return false;
            }
        }
        return true;
    }
};