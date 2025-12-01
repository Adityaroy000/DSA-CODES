class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);

        while(true){
            int idx = -1;
            for(int i=n-2;i>=0;i--){
                if(nums[i]<nums[i+1]){
                    idx = i;
                    break;
                }
            }
            if(idx == -1) break;
            for(int i=n-1;i>idx;i--){
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    break;
                }
            }
            reverse(nums.begin()+idx+1,nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};