class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxxor = 0;
        int j = 0;
        for(int i=0;i<n;i++){
            j=i;
           while(j<n && nums[j] <= 2*nums[i]){
                maxxor = max(maxxor,nums[i]^nums[j]);
                j++;
           }
        }
        
        return maxxor;
    }
};