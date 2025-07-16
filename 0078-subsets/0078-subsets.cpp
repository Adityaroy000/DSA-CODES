class Solution {
public:
    void solve(vector<int>& arr,vector<int> nums,vector<vector<int>>& ans){
        if(nums.size()==0){
            ans.push_back(arr);
            return;
        }

        vector<int>a1 = arr;
        vector<int>a2 = arr;
        a2.push_back(nums[0]);

        nums.erase(nums.begin()+0);

        solve(a1,nums,ans);
        solve(a2,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;

        vector<vector<int>> ans;

        solve(arr,nums,ans);
        return ans;
    }
};