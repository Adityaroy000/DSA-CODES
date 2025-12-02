class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int prev = 0;
        int curr = prev+1,last = n-1;
        vector<vector<int>>ans;
        while(prev<n-2){
            if(prev>0) while(prev<n-2 &&nums[prev]==nums[prev-1]) prev++;
            curr = prev+1;
            last = n-1;
            while(curr<last){
                int sum = nums[prev]+nums[curr]+nums[last];
                if(sum < 0){
                    curr++;
                }else if(sum>0){
                    last--;
                }else{
                    ans.push_back({nums[prev],nums[curr],nums[last]});
                    curr++;
                    last--;
                    while(curr<last && nums[curr]==nums[curr-1]) curr++;
                    while(curr<last && nums[last]==nums[last+1]) last--;
                }
            }
            prev++;
        }
        return ans;
    }
};